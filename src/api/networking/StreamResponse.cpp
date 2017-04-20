

#include "StreamResponse.h"

StreamResponse::~StreamResponse() {
    setHeader("Content-Type", "text/plain");
}

StreamResponse::StreamResponse() {

}

std::string StreamResponse::getBody() {
    return this->str();
}
