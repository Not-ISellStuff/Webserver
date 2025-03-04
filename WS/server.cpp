#include <iostream>
#include <windows.h>
#include <winsock2.h>

#include "app.h"
#include "../server.h"

Server webserver;

DWORD WINAPI AcceptConnections(LPVOID param) { 
    while (1) {
        if (webserver.connections.size() != MAX_CONN) {
            SOCKET client = accept(webserver.server, NULL, NULL);
            webserver.connections.push_back(client);

            std::cout << "\n[+] New HTTP Request\n";
        }
    }
}

void startTAC() {
    DWORD tid;

    CreateThread(
        NULL,               
        0,                 
        AcceptConnections,               
        NULL,            
        0,                  
        &tid          
    );
}

int main() {
    SOCKET server = START(SERVER, PORT);

    if (server == INVALID_SOCKET) {
        std::cout << "\n[!] Failed To Start Server.\n";
        exit(EXIT_FAILURE);
    }

    webserver.server = server;
    startTAC();
    std::cout << "[+] Server Is Up.\n";

    while (1) {
        if (webserver.connections.size() > 0) {
            char request[1024] = {0};

            for (int i = 0; i < webserver.connections.size(); i++) {
                memset(request, 0, sizeof(request));
                recv(webserver.connections[i], request, 1024, 0);

                Handle(webserver.connections[i], request);
                closesocket(webserver.connections[i]);
            }
            
            webserver.connections.clear();
        }
    }
}
