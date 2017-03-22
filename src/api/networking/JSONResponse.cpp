

#include "JSONResponse.h"

JSONResponse::JSONResponse() {

}

JSONResponse::~JSONResponse() {

}

std::string JSONResponse::getBody() {
    Json::FastWriter writer;
    return writer.write(*this);
}
