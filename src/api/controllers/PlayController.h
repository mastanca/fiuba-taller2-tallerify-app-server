

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_PLAYCONTROLLER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_PLAYCONTROLLER_H

#include <regex>
#include "Controller.h"
#include "../networking/JSONResponse.h"

/**
 * @file PlayController.h
 */
class PlayController : public Controller {
public:
    /**
     * Constructor
     */
    PlayController();

    /**
     * Destructor
     */
    virtual ~PlayController();

    /**
     * Returns if current controller handles the given method and url
     * @param method the http method of the request
     * @param url of the request
     * @return true if handles, false otherwise
     */
    bool handles(std::string method, std::string url);

    /**
     * Process the given request and respond accordingly
     * @param request to process
     * @return the corresponding response
     */
    Response *process(Request &request);

    /**
     * Get the static file *.mp3
     * @param request request with the song to play
     * @param response with the static file if file exists, 404 otherwise
     */
    void get(Request &request, JSONResponse &response);

private:
    std::regex playRegex;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_PLAYCONTROLLER_H
