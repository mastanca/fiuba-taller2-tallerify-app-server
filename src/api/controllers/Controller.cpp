

#include <spdlog/spdlog.h>
#include "Controller.h"
#include "../networking/JSONResponse.h"
#include "../config/Constants.h"

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
    // Only JSON responses so..
    JSONResponse *response = new JSONResponse();
    response->setCode(HTTP_SERVER_ERROR);
    spdlog::get("console")->error("500: {}", message);
    return response;
}

void Controller::addRoute(std::string httpVerb, std::string route, RequestHandlerBase *handler) {
    std::string key = httpVerb + ":" + route;
    routes[key] = handler;
    urls.push_back(route);
}

bool Controller::handles(std::string method, std::string url) {
    std::string key = method + ":" + url;
    return routes.find(key) != routes.end();
}

void Controller::setElementId(Request &request) {
    std::string elementIdString;
    std::size_t found = request.getUrl().rfind("/");
    if (found != std::string::npos) {
        elementIdString = request.getUrl().substr(found + 1);
        try {
            request.setElementId(std::stoi(elementIdString));
        } catch (...) {
            spdlog::get("console")->warn("Couldn't set {} as int element id", elementIdString);
        }
        request.setElementIdString(elementIdString);
    }
}
