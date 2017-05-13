

#include "TracksControllerTest.h"
#include "../../src/api/dao/MongoDao.h"
#include "../../src/api/controllers/TracksController.h"
#include "../../src/api/config/Constants.h"

void TracksControllerTest::testTrackFound() {
    MongoDao *dao = new MongoDao();
    std::string songLocation = "/music/paint_it_black.mp3";
    int id = rand() + 1;
    Track track(id, songLocation);
    dao->saveTrack(&track);
    delete dao;

    TracksController controller;
    Response *response = NULL;
    http_message message;
    std::string body = "";
    std::string method = HTTP_GET;
    std::string uri = "/tracks/" + std::to_string(id);
    message.body = mg_mk_str(body.c_str());
    message.method = mg_mk_str(method.c_str());
    message.uri = mg_mk_str(uri.c_str());
    mg_connection connection;
    Request request(&connection, &message);
    response = controller.process(request);

    ASSERT_EQ(response->getBody(), "{\"trackId\":" + std::to_string(id) + ",\"url\":\"" + BASE_URL + songLocation + "\"}\n");
    delete response;
}

void TracksControllerTest::testTrackNotFound() {
    TracksController controller;
    JSONResponse *response = new JSONResponse();
    http_message message;
    std::string body = "";
    std::string method = HTTP_GET;
    std::string uri = "/tracks/999";
    message.body = mg_mk_str(body.c_str());
    message.method = mg_mk_str(method.c_str());
    message.uri = mg_mk_str(uri.c_str());
    mg_connection connection;
    Request *request = new Request(&connection, &message);
    controller.get(*request, *response);

    ASSERT_EQ(response->getCode(), HTTP_NOT_FOUND);
    delete response;
    delete request;
}

void TracksControllerTest::testPostTrack() {
    TracksController controller;
    std::string filename = "asd";
    controller.post(124, filename.c_str());
    MongoDao dao;
    Track *track = dao.getTrack(124);
    ASSERT_EQ(track->getId(), 124);
    delete(track);
}
