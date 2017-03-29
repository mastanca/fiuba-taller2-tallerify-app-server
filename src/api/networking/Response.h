

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_RESPONSE_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_RESPONSE_H

#include <string>
#include <map>

class Response {
public:
    Response();

    virtual ~Response();

    void setHeader(std::string key, std::string value);

    void setCode(int code);

    int getCode() const;

    virtual std::string getData();

    virtual std::string getBody() = 0;

    virtual bool hasHeader(std::string key);

protected:
    int code;
    std::map<std::string, std::string> headers;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_RESPONSE_H
