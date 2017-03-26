

#include "PingController.h"
#include "../config/Constants.h"

PingController::PingController() {
    init();
}

PingController::~PingController() {

}

void PingController::get(Request &request, JSONResponse &response) {
    response["ping"] = "pong";
}

void PingController::init() {
    addRoute(HTTP_GET, "/ping", new RequestHandler<PingController, JSONResponse>(this, &PingController::get));
}

