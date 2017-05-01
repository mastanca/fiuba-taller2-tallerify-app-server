

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_REQUEST_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_REQUEST_H


#include <mongoose/mongoose.h>
#include "Response.h"

/**
 * @file Request.h
 */
class Request {
public:
    /**
     * Request constructor
     * Builds request from the mongoose connection and httpmessage
     * Parses httpmethod, body and url
     * @param connection
     * @param httpMessage
     */
    Request(mg_connection *connection, http_message *httpMessage);

    /**
     * Request destroyer
     */
    virtual ~Request();

    /**
     * Writes response back to client
     * @param response the response to write
     */
    virtual void writeResponse(Response *response);

    /**
     * Request url getter
     * @return associated url
     */
    virtual const std::string &getUrl() const;

    /**
     * Request body getter
     * @return parsed body
     */
    virtual const std::string &getBody() const;

    /**
     * Request http verb getter
     * @return parsed http verb
     */
    virtual const std::string &getHttpVerb() const;

private:
    mg_connection *connection;
    std::string url;
    std::string body;
    std::string httpVerb;

    void parseMessage(http_message *httpMessage);
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_REQUEST_H
