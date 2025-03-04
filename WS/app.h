#ifndef APP_H 
#define APP_H

#include <winsock2.h>
#include <string>
#include <iostream> 

#ifdef __cplusplus
extern "C" {
#endif

int SEND(SOCKET client, const char* request); 
SOCKET START(const char *SERVER, const int PORT);  

#ifdef __cplusplus
}  
std::string parseReq(char *req);
void Handle(SOCKET client, char *response);

#endif  
#endif
