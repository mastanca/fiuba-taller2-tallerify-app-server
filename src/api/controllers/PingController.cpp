

#include "PingController.h"

PingController::PingController() {
    init();
}

PingController::~PingController() {

}

void PingController::get(Request &request, JSONResponse &response) {
   response["ping"] = "pong";
}

void PingController::init() {
    //addRouteResponse(HTTP_GET, "/ping", PingController, get, JSONResponse);
    addRoute(HTTP_GET, "/ping", new RequestHandler<PingController, JSONResponse>(this, &PingController::get ));
}

