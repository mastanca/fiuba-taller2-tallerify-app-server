

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_PINGCONTROLLER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_PINGCONTROLLER_H

#include "Controller.h"
#include "../networking/JSONResponse.h"

class PingController : public Controller {
public:
    PingController();

    virtual ~PingController();

    void get(Request &request, JSONResponse &response);

protected:
    void init();
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_PINGCONTROLLER_H
