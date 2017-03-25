

#include "Controller.h"

Controller::Controller() {

}

Controller::~Controller() {
    std::map<std::string, RequestHandlerBase *>::iterator it;

    for (it = routes.begin(); it != routes.end(); it++) {
        delete (*it).second;
    }

    routes.clear();
}

Response *Controller::process(Request &request) {
    Response *response = NULL;

    std::string key = request.getHttpVerb() + ":" + request.getUrl();
    if (routes.find(key) != routes.end()) {
        response = routes[key]->process(request);
    }

    return response;
}

Response *Controller::serverInternalError(std::string message) {
    Response *response = new Response();

    response->setCode(HTTP_SERVER_ERROR);

    return response;
}

void Controller::addRoute(std::string httpVerb, std::string route, RequestHandlerBase *handler) {
    std::string key = httpVerb + ":" + route;
    routes[key] = handler;
    urls.push_back(route);
}