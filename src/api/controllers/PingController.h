

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_PINGCONTROLLER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_PINGCONTROLLER_H

#include "Controller.h"
#include "../networking/JSONResponse.h"

/**
 * @file PingController.h
 */
class PingController : public Controller {
public:
    /**
     * PingController constructor
     */
    PingController();

    /**
     * PingController destroyer
     */
    virtual ~PingController();

    /**
     * ping method, resturns built jsonresponse with pong
     * @param request the request to get data from
     * @param response the prepared response, ready to serve
     */
    void get(Request &request, JSONResponse &response);
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_PINGCONTROLLER_H
