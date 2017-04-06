

#include "Track.h"
#include "base64/base64.h"
#include <ostream>

Track::Track(int id, std::string bytes, bool encode) : id(id), base64EncodedBytes(bytes) {
    if (encode) base64EncodedBytes = base64_encode(bytes);
}

Track::~Track() {

}

int Track::getId() const {
    return id;
}

const std::string &Track::getBase64EncodedBytes() const {
    return base64EncodedBytes;
}

void Track::setId(int id) {
    this->id = id;
}

void Track::setBase64EncodedBytes(const std::string &base64EncodedBytes) {
    this->base64EncodedBytes = base64EncodedBytes;
}
