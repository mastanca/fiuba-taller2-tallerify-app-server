

#include "TracksController.h"
#include "../config/Constants.h"
#include "../dao/MongoDao.h"

TracksController::TracksController() {
    addRoute(HTTP_GET, "/tracks/",
             new RequestHandler<TracksController, StreamResponse>(this, &TracksController::get));
}

TracksController::~TracksController() {

}

void TracksController::get(Request &request, StreamResponse &response) {
    MongoDao dao;
    Track *track = dao.getTrack(1122265510);
    response << track->getBase64EncodedBytes();
    // TODO: Open new udp socket and start streaming
    delete track;
}
