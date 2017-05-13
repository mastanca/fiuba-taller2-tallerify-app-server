

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
     * Request constructor for multipart requests
     * @param connection
     * @param event
     * @param eventData
     */
    Request(mg_connection *connection, int event, void *eventData);

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

    /**
     * Get request's element id
     * @return element id
     */
    int getElementId() const;

    /**
     * Set the request's element id
     * @param elementId the element id to set
     */
    void setElementId(int elementId);

    /**
     * Set the url of the request
     * @param url to set
     */
    void setUrl(const std::string &url);

    /**
     * Get the associated connection
     * @return the connection
     */
    mg_connection *getConnection() const;

    /**
     * Get the original http message
     * @return the http message
     */
    http_message *getHttpMessage() const;

    /**
     * Get the element id as string
     * @return element id as string
     */
    const std::string &getElementIdString() const;

    /**
     * Set the elementId as a string
     * @param elementIdString to set
     */
    void setElementIdString(const std::string &elementIdString);

    /**
     * Event getter
     * @return the event code
     */
    int getEvent() const;

    /**
     * Event data getter
     * @return the event data as void*
     */
    void *getEventData() const;


private:
    mg_connection *connection;
    http_message *httpMessage;
    std::string url;
    std::string body;
    std::string httpVerb;
    int elementId;
    std::string elementIdString;
    int event;
    void *eventData;

    void parseMessage(http_message *httpMessage);
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_REQUEST_H
