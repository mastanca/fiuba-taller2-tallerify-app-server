

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_MONGODAO_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_MONGODAO_H


#include <mongocxx/database.hpp>
#include <mongocxx/instance.hpp>
#include "../domain/Track.h"

/**
 * @file MongoDao.h
 */
class MongoDao {
public:
    /**
     * MongoDao constructor
     * Creates a valid connection with mongodb
     */
    MongoDao();

    /**
     * MongoDao destroyer
     * freed resources allocated on construction
     */
    virtual ~MongoDao();

    /**
     * Saves new track to db
     * @param track track object to save
     */
    void saveTrack(Track *track);

    /**
     * Returns track fetched from db
     * @param trackId track id to search for
     * @return fetched track
     */
    Track *getTrack(int trackId);

private:
    mongocxx::client *client;
    mongocxx::instance *instance;
    mongocxx::database db;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_MONGODAO_H
