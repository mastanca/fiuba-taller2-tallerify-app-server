

#ifndef FIUBA_TALLER2_TALLERIFY_APP_SERVER_BASE64_H
#define FIUBA_TALLER2_TALLERIFY_APP_SERVER_BASE64_H

#include <string>

std::string base64_encode(std::string);
std::string base64_encode(unsigned char const* , unsigned int len);
std::string base64_decode(std::string const& s);

#endif //FIUBA_TALLER2_TALLERIFY_APP_SERVER_BASE64_H
