

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSE_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSE_H

#include "jsoncpp/json/json.h"
#include "Response.h"

/**
 * #
 * @file JSONResponse.h
 */
class JSONResponse : public Json::Value, public Response {
public:
    /**
     * JSONResponse constructor
     * Sets json headers
     */
    JSONResponse();

    /**
     * JSONResponse destroyer
     */
    virtual ~JSONResponse();

    /**
     * Returns current response body, json formatted
     * @return the body as a string
     */
    virtual std::string getBody();
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSE_H
