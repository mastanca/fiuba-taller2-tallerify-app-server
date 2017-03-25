#ifndef _MONGOOSE_REQUEST_HANDLER_H
#define _MONGOOSE_REQUEST_HANDLER_H

#include "../../src/api/networking/Request.h"
#include "../../src/api/networking/Response.h"
#include <string>


class RequestHandlerBase {
public:
    virtual Response *process(Request &request)=0;
    virtual ~RequestHandlerBase();
};

template<typename T, typename R>
class RequestHandler : public RequestHandlerBase {
public:
    typedef void (T::*fPtr)(Request &request, R &response);

    RequestHandler(T *controller_, fPtr function_)
            : controller(controller_), function(function_) {
    }

    Response *process(Request &request) {
        R *response = new R;

        try {
            (controller->*function)(request, *response);
        } catch (std::string exception) {
            return controller->serverInternalError(exception);
        } catch (...) {
            return controller->serverInternalError("Unknown error");
        }

        return response;
    }

    virtual ~RequestHandler();

protected:
    T *controller;
    fPtr function;
};

#endif