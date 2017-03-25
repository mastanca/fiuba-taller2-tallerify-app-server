

#include "Response.h"

Response::Response() : code(HTTP_OK), headers() {

}

Response::~Response() {}

void Response::setCode(int code) {
    Response::code = code;
}

void Response::setHeader(std::string key, std::string value) {
    headers[key] = value;
}
