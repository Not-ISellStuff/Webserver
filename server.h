#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>
#include <vector>
#include <iostream>

#define SERVER "127.0.0.1"
#define PORT 8080
#define MAX_CONN 30     /*
                        Clients to handle at the same time

                        Connection is closed after a request 
                        */

typedef struct Server {
    SOCKET server;           
    std::vector<SOCKET> connections;    
} Server;

#endif
