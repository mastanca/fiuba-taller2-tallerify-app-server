

#include <spdlog/spdlog.h>
#include "TracksController.h"
#include "../config/Constants.h"
#include "../dao/MongoDao.h"

TracksController::TracksController() {
    tracksRegex = "/tracks/.*";
    addRoute(HTTP_GET, "/tracks/",
             new RequestHandler<TracksController, JSONResponse>(this, &TracksController::get));
    addRoute(HTTP_POST, "/tracks",
             new RequestHandler<TracksController, JSONResponse>(this, &TracksController::post));
}

TracksController::~TracksController() {

}

bool TracksController::handles(std::string method, std::string url) {
    if (method == HTTP_GET && url != "/tracks" && std::regex_match(url, tracksRegex)) {
        return true;
    } else {
        return Controller::handles(method, url);
    }
}

Response *TracksController::process(Request &request) {
    Response *response = NULL;

    response = Controller::process(request);
    if (!response && request.getHttpVerb() == HTTP_GET) {
        // It's a GET /tracks/$id
        setElementId(request);
        request.setUrl("/tracks/");
        response = Controller::process(request);
    }

    return response;
}

void TracksController::get(Request &request, JSONResponse &response) {
    MongoDao dao;
    Track *track = dao.getTrack(request.getElementId());
    if (!track) {
        response.setCode(HTTP_NOT_FOUND);
        spdlog::get("console")->warn("Response from {0} {1} was {2}", request.getHttpVerb(), request.getUrl(),
                                     response.getCode());
        return;
    }
    response["trackId"] = track->getId();
    response["url"] = BASE_URL + track->getFileLocation(); // TODO: Get the real one
    delete track;
}

void TracksController::post(Request &request, JSONResponse &response) {
    spdlog::get("console")->info("Inside tracks post");
}
