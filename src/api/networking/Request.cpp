

#include "Request.h"
#include "spdlog/spdlog.h"

Request::Request(mg_connection *connection, http_message *httpMessage) : connection(connection), url(""), body(""),
                                                                         httpVerb("") {
    parseMessage(httpMessage);
    spdlog::get("console")->info("Processing request {0} {1}", httpVerb, url);
}

Request::~Request() {

}

void Request::writeResponse(Response *response) {
    std::string data = response->getData();
    mg_printf(connection, "%s", data.c_str());
}

void Request::parseMessage(http_message *httpMessage) {
    for (size_t i = 0; i < httpMessage->method.len; ++i) {
        httpVerb += httpMessage->method.p[i];
    }

    for (size_t i = 0; i < httpMessage->uri.len; ++i) {
        url += httpMessage->uri.p[i];
    }

    for (size_t i = 0; i < httpMessage->body.len; ++i) {
        body += httpMessage->body.p[i];
    }
}

const std::string &Request::getUrl() const {
    return url;
}

const std::string &Request::getBody() const {
    return body;
}

const std::string &Request::getHttpVerb() const {
    return httpVerb;
}
