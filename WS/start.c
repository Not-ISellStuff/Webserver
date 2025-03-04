#include <stdio.h>
#include <winsock2.h>

SOCKET START(const char *SERVER, const int PORT, int MAX_CONN) {
    SOCKET server;
    WSADATA wsa;
    struct sockaddr_in server_address;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("\n[!] Winsock Initialization Failure.\n");
        return INVALID_SOCKET;
    }

    server = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER);  
    server_address.sin_port = htons(PORT);

    if (bind(server, (struct sockaddr *)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        closesocket(server);
        WSACleanup();
        printf("\n[+] Failed To Bind Server Socket.\n");
        return INVALID_SOCKET;
    }

    if (listen(server, MAX_CONN) == INVALID_SOCKET) {
        printf("\n[!] %d\n", WSAGetLastError());
        WSACleanup();
        closesocket(server);
        return INVALID_SOCKET;
    }

    return server;
}
