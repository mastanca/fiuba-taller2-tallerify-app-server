

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
     * PingCOntroller destroyer
     */
    virtual ~PingController();

    /**
     * ping method, resturns built jsonresponse with pong
     * @param request
     * @param response
     */
    void get(Request &request, JSONResponse &response);
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_PINGCONTROLLER_H
