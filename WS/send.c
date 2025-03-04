#include <winsock2.h>
#include <stdio.h>
#include <windows.h>

int SEND(SOCKET client, const char* file) {
    FILE *html;
    char path[50], buffer[1024] = {0};

    sprintf(path, "Site/%s", file);
    html = fopen(path, "r");

    if (html == NULL) {
        const char* not_found = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>";
        send(client, not_found, strlen(not_found), 0);
        return 1;
    }

    const char* headers = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    send(client, headers, strlen(headers), 0);

    size_t bytes_read = fread(buffer, 1, sizeof(buffer), html);

    while (bytes_read > 0) {
        send(client, buffer, bytes_read, 0);
        bytes_read = fread(buffer, 1, sizeof(buffer), html);  
    }

    fclose(html);
    return 0;
}
