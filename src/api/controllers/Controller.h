

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_CONTROLLER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_CONTROLLER_H


#include "../networking/Request.h"
#include <mongoose/RequestHandler.h>
#include <vector>

#define HTTP_GET "GET"
#define HTTP_POST "POST"
#define HTTP_PUT "PUT"
#define HTTP_DELETE "DELETE"

class Controller {
public:
    Controller();

    virtual ~Controller();

    virtual Response *process(Request &request);

    Response *serverInternalError(std::string message);

    void addRoute(std::string httpVerb, std::string route, RequestHandlerBase *handler);

protected:
    std::map<std::string, RequestHandlerBase *> routes;
    std::vector<std::string> urls;

    virtual void init() {}

};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_CONTROLLER_H
