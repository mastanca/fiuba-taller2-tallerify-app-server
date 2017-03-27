

#include "JSONResponse.h"

JSONResponse::JSONResponse() {
    setHeader("Content-Type", "application/json");
}

JSONResponse::~JSONResponse() {

}

std::string JSONResponse::getBody() {
    Json::FastWriter writer;
    return writer.write(*this);
}
