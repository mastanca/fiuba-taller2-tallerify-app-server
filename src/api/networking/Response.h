

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_RESPONSE_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_RESPONSE_H

#include <string>
#include <map>

#define HTTP_OK 200
#define HTTP_CREATED 201
#define HTTP_BAD_REQUEST 400
#define HTTP_NOT_FOUND 404
#define HTTP_FORBIDDEN 403
#define HTTP_SERVER_ERROR 500

class Response {
public:
    Response();

    virtual ~Response();

    void setHeader(std::string key, std::string value);

    void setCode(int code);

protected:
    int code;
    std::map<std::string, std::string> headers;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_RESPONSE_H
