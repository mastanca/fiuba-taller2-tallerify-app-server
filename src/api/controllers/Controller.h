

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
     * @param request
     * @return built response, with status code
     */
    virtual Response *process(Request &request);

    /**
     * Prepares 500 error in case of error during process
     * @param message
     * @return 500 status code response
     */
    Response *serverInternalError(std::string message);

    /**
     * Adds route to controller's routes map. Mongoose's requesthandlerbase does the mapping
     * @param httpVerb
     * @param route
     * @param handler
     */
    void addRoute(std::string httpVerb, std::string route, RequestHandlerBase *handler);

    /**
     * Checks if controller handles the given url
     * @param method
     * @param url
     * @return true if it handles, false otherwise
     */
    virtual bool handles(std::string method, std::string url);

protected:
    std::map<std::string, RequestHandlerBase *> routes;
    std::vector<std::string> urls;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_CONTROLLER_H
