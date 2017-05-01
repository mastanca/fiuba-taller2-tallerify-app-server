

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACK_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACK_H


#include <string>

/**
 * @file Track.h
 */
class Track {
public:
    /**
     * Track constructor
     * @param id the id of the track
     * @param fileLocation location of the associated file in filesystem
     */
    Track(int id, std::string fileLocation);

    /**
     * Track destroyer
     */
    virtual ~Track();

private:
    int id;
    std::string fileLocation;

public:
    /**
     * id getter
     * @return track's id
     */
    int getId() const;

    /**
     * file location getter
     * @return file location
     */
    const std::string &getFileLocation() const;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACK_H
