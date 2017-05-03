

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_RESPONSE_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_RESPONSE_H

#include <string>
#include <map>

/**
 * @file Response.h
 */
class Response {
public:
    /**
     * Response constructor
     */
    Response();

    /**
     * Response destroyer
     */
    virtual ~Response();

    /**
     * inserts a new header to the headers map
     * @param key string containing the header key
     * @param value string containing the header value
     */
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
