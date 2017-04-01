

#include <mongoose/mongoose.h>
#include "RequestTest.h"
#include "../../src/api/config/Constants.h"
#include "../../src/api/networking/Request.h"


void RequestTest::testHttpInitialization() {
    http_message message;
    std::string body = "hola";
    std::string method = HTTP_GET;
    std::string uri = "/uri";
    message.body = mg_mk_str(body.c_str());
    message.method = mg_mk_str(method.c_str());
    message.uri = mg_mk_str(uri.c_str());

    Request request(NULL, &message);
    ASSERT_EQ(request.getBody(), body);
    ASSERT_EQ(request.getHttpVerb(), method);
    ASSERT_EQ(request.getUrl(), uri);
}
