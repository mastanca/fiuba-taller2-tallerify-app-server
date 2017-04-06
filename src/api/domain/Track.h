

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACK_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACK_H


#include <string>

class Track {
public:
    // TODO: Receive bytes
    Track(int id, std::string bytes, bool encode = true);

    virtual ~Track();

private:
    int id;
public:
    int getId() const;

    void setId(int id);

    const std::string &getBase64EncodedBytes() const;

    void setBase64EncodedBytes(const std::string &base64EncodedBytes);

    std::string toString();

private:
    std::string base64EncodedBytes;
};


#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_TRACK_H
