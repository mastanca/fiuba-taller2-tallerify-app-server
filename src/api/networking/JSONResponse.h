

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSE_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSE_H

#include "jsoncpp/json/json.h"
#include "Response.h"

class JSONResponse : public Json::Value, public Response {
public:
    JSONResponse();

    virtual ~JSONResponse();

    virtual std::string getBody();
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_JSONRESPONSE_H
