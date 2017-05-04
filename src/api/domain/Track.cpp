

#include "Track.h"
#include <ostream>

Track::Track(int id, std::string fileLocation) : id(id), fileLocation(fileLocation) {
}

Track::~Track() {

}

int Track::getId() const {
    return id;
}

const std::string &Track::getFileLocation() const {
    return fileLocation;
}

