

#include <spdlog/spdlog.h>
#include "TracksController.h"
#include "../config/Constants.h"
#include "../dao/MongoDao.h"

struct mg_str TracksController::upload_fname(struct mg_connection *c, struct mg_str file_name) {
    // Return the same filename. Do not actually do this except in test!
    // fname is user-controlled and needs to be sanitized.
    std::string *final = new std::string("../music/" + std::string(file_name.p));
    return mg_mk_str(final->c_str());
}

TracksController::TracksController() : tracksRegex("/tracks/.*"), fileName(""){
    addRoute(HTTP_GET, "/tracks/",
             new RequestHandler<TracksController, JSONResponse>(this, &TracksController::get));
    /*addRoute(HTTP_POST, "/tracks",
             new RequestHandler<TracksController, JSONResponse>(this, &TracksController::post));*/
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
    response["url"] = BASE_URL + track->getFileLocation();
    delete track;
}

void TracksController::post(int trackId, const char* filename) {
        setFileName(filename);
        MongoDao dao;
        Track *track = new Track(trackId, fileName);
        dao.saveTrack(track);
        delete track;
}

void TracksController::setFileName(const char *fileName) {
    TracksController::fileName = "/music/" + std::string(fileName);
}
