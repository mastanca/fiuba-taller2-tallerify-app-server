

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_REQUEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_REQUEST_H


#include <mongoose/mongoose.h>
#include "Response.h"

class Request {
public:
    Request(mg_connection *connection, http_message *httpMessage);

    virtual ~Request();

    virtual void writeResponse(Response *response);

    virtual const std::string &getUrl() const;

    virtual const std::string &getBody() const;

    virtual const std::string &getHttpVerb() const;

private:
    mg_connection *connection;
    std::string url;
    std::string body;
    std::string httpVerb;

    void parseMessage(http_message *httpMessage);
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_REQUEST_H
