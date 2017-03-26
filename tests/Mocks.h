

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_MOCKS_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_MOCKS_H

#include "gmock/gmock.h"
#include "../src/api/networking/Request.h"

class MockRequest : public Request {
public:
    MockRequest(mg_connection *connection, http_message *httpMessage) : Request(connection, httpMessage) {}
    MOCK_METHOD1(writeResponse, void(Response *response));
    MOCK_CONST_METHOD0(getUrl, std::string &());
    MOCK_CONST_METHOD0(getBody, std::string &());
    MOCK_CONST_METHOD0(getHttpVerb, std::string &());
};

#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_MOCKS_H
