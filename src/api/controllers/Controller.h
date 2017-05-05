

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_CONTROLLER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_CONTROLLER_H


#include "../networking/Request.h"
#include <mongoose/RequestHandler.h>
#include <vector>

/**
 * @file Controller.h
 */
class Controller {
public:
    /**
     * Controller constructor
     */
    Controller();

    /**
     * Controller destroyer
     */
    virtual ~Controller();

    /**
     * processes passed request
     * gets the corresponding method from its routes and calls method
     * @param request the request to process
     * @return built response, with status code
     */
    virtual Response *process(Request &request);

    /**
     * Prepares 500 error in case of error during process
     * @param message error response message
     * @return 500 status code response
     */
    Response *serverInternalError(std::string message);

    /**
     * Adds route to controller's routes map. Mongoose's requesthandlerbase does the mapping
     * @param httpVerb one of GET/POST/PUT/DELETE
     * @param route route to handle. ex: /tracks
     * @param handler Mongoose's request handler
     */
    void addRoute(std::string httpVerb, std::string route, RequestHandlerBase *handler);

    /**
     * Checks if controller handles the given url
     * @param method one of GET/POST/PUT/DELETE
     * @param url the one to verify. ex: /ping
     * @return true if it handles, false otherwise
     */
    virtual bool handles(std::string method, std::string url);

protected:
    std::map<std::string, RequestHandlerBase *> routes;
    std::vector<std::string> urls;

    /**
     * Set the element id of the request
     * @param request to set it's element id
     */
    void setElementId(Request &request);
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_CONTROLLER_H
