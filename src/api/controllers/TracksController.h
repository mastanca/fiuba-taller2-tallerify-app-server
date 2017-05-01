

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLER_H


#include "Controller.h"
#include "../networking/JSONResponse.h"

class TracksController : public Controller {
public:
    TracksController();

    virtual ~TracksController();

    void get(Request &request, JSONResponse &response);

};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLER_H
