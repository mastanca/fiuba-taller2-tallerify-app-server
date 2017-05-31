

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLER_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLER_H


#include "Controller.h"
#include "../networking/JSONResponse.h"
#include <regex>

/**
 * @file TracksController.h
 */
class TracksController : public Controller {
public:
    /**
     * constructor
     */
    TracksController();

    /**
     * destroyer
     */
    virtual ~TracksController();

    /**
     * Returns if the controller handles the given method and url
     * @param method the http method
     * @param url the request url
     * @return true if handles, false otherwise
     */
    bool handles(std::string method, std::string url);

    /**
     * Process the given request and respond accordingly
     * @param request to process
     * @return The corresponding response
     */
    Response *process(Request &request);

    /**
     * Get the given track
     * @param request with the track id
     * @param response containing the track id and the play url
     */
    void get(Request &request, JSONResponse &response);

    /**
     * Post a track to create it
     * @param trackId
     * @param filename
     */
    void post(int trackId, const char* filename);

    /**
     * Sets the filename of the file being uploaded
     * @param fileName
     */
    void setFileName(const char *fileName);

    static struct mg_str upload_fname(struct mg_connection *c, struct mg_str file_name);


private:
    std::regex tracksRegex;
    std::string fileName;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACKSCONTROLLER_H
