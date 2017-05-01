

#include <mongocxx/client.hpp>
#include <spdlog/spdlog.h>
#include <bsoncxx/json.hpp>
#include <mongocxx/instance.hpp>
#include "MongoDao.h"

MongoDao::MongoDao() {
    instance = new mongocxx::instance();
    char *compose = getenv("COMPOSE");
    if (compose == NULL || strcmp(compose,"true")) {
        client = new mongocxx::client(mongocxx::uri{});
    } else {
        mongocxx::uri uri("mongodb://db:27017");
        client = new mongocxx::client(uri);
    }
    db = (*client)["tallerify"];
}

void MongoDao::saveTrack(Track *track) {
    bsoncxx::builder::stream::document document{};

    mongocxx::collection collection = db["tracks"];
    document << "_id" << track->getId()
             << "file_location" << track->getFileLocation();
    collection.insert_one(document.view());
    spdlog::get("console")->info("Saved track: {0}", bsoncxx::to_json(document.view()));
}

MongoDao::~MongoDao() {
    delete client;
    delete instance;
}

Track *MongoDao::getTrack(int trackId) {
    mongocxx::collection collection = db["tracks"];
    mongocxx::stdx::optional<bsoncxx::document::value> found =
            collection.find_one(
                    bsoncxx::builder::stream::document{} << "_id" << trackId << bsoncxx::builder::stream::finalize);
    if (found) {
        auto doc = (*found).view();
        bsoncxx::stdx::string_view view = doc["file_location"].get_utf8().value;
        return new Track(doc["_id"].get_int32(), view.to_string());
    }
    return NULL;
}
