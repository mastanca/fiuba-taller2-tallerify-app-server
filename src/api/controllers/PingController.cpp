

#include "PingController.h"
#include "../config/Constants.h"

PingController::PingController() {
    addRoute(HTTP_GET, "/ping", new RequestHandler<PingController, JSONResponse>(this, &PingController::get));
}

PingController::~PingController() {

}

void PingController::get(Request &request, JSONResponse &response) {
    response["ping"] = "pong";
}

