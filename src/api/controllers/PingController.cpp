

#include "PingController.h"

PingController::PingController() {

}

PingController::~PingController() {

}

void PingController::get(Request &request, JSONResponse response) {
    response["ping"] = "pong";
}

