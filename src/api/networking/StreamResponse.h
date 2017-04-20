

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_STREAMRESPONSE_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_STREAMRESPONSE_H


#include <sstream>
#include "Response.h"

class StreamResponse : public std::ostringstream, public Response {
public:
    StreamResponse();
    virtual ~StreamResponse();
    virtual std::string getBody();

};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_STREAMRESPONSE_H
