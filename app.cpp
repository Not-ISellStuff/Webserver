#include <iostream>
#include <winsock2.h>

#include "WS/app.h"

std::string parseReq(char req[1024]) {
    std::string request(req);

    size_t newline_pos = request.find("\r\n");
    if (newline_pos == std::string::npos) return "";

    std::string first_line = request.substr(0, newline_pos);

    size_t pos = first_line.find(" ");
    if (pos == std::string::npos) return "";

    size_t ps = pos + 1;
    size_t pe = first_line.find(" ", ps);
    if (pe == std::string::npos) return "";

    return first_line.substr(ps, pe - ps);
}


void Handle(SOCKET client, char response[1024]) {
    std::string resp = parseReq(response);

    std::cout << resp;

    if (resp == "/") {
        SEND(client, "index.html");
    } else {
        SEND(client, "not_found.html");
    }
}
