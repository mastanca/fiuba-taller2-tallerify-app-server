

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLER_H


#include "Controller.h"
#include "../networking/JSONResponse.h"
#include <regex>

class TracksController : public Controller {
public:
    TracksController();

    virtual ~TracksController();

    void get(Request &request, JSONResponse &response);

    bool handles(std::string method, std::string url);

    Response *process(Request &request);
private:
    std::regex tracksRegex;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLER_H
