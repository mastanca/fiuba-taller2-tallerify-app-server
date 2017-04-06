

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_MONGODAO_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_MONGODAO_H


#include <mongocxx/database.hpp>
#include <mongocxx/instance.hpp>
#include "../domain/Track.h"

class MongoDao {
public:
    MongoDao();

    virtual ~MongoDao();

    void saveTrack(int trackId, std::string base64EncodedBytes);

    Track *getTrack(int trackId);

private:
    mongocxx::client *client;
    mongocxx::instance *instance;
    mongocxx::database db;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_MONGODAO_H
