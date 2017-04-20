

#include "Response.h"
#include <sstream>
#include "../config/Constants.h"

Response::Response() : code(HTTP_OK), headers() {

}

Response::~Response() {}

void Response::setCode(int code) {
    Response::code = code;
}

void Response::setHeader(std::string key, std::string value) {
    headers[key] = value;
}

int Response::getCode() const {
    return code;
}

std::string Response::getData() {
    std::string body = getBody();
    std::ostringstream data;

    data << "HTTP/1.1 " << code << "\n";

    if (!hasHeader("Content-Length")) {
        std::ostringstream length;
        length << body.size();
        setHeader("Content-Length", length.str());
    }

    std::map<std::string, std::string>::iterator it;
    for (it = headers.begin(); it != headers.end(); it++) {
        data << (*it).first << ": " << (*it).second << "\n";
    }

    data << "\n";

    data << body;

    return data.str();
}

bool Response::hasHeader(std::string key) {
    return headers.find(key) != headers.end();
}
