

#include <mongocxx/client.hpp>
#include <spdlog/spdlog.h>
#include <bsoncxx/json.hpp>
#include <mongocxx/instance.hpp>
#include "MongoDao.h"

MongoDao::MongoDao() {
    instance = new mongocxx::instance();
    client = new mongocxx::client(mongocxx::uri{});
    db = (*client)["tallerify"];
}

void MongoDao::saveTrack(int trackId, std::string base64EncodedBytes) {
    bsoncxx::builder::stream::document document{};

    mongocxx::collection collection = db["tracks"];
    document << "_id" << trackId
             << "base64_encoded_bytes" << base64EncodedBytes;
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
        bsoncxx::stdx::string_view view = doc["base64_encoded_bytes"].get_utf8().value;
        return new Track(doc["_id"].get_int32(), view.to_string());
    }
    return NULL;
}
