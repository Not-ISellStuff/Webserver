# Webserver
Basic Web Server written in C and C++ for windows, It's pretty bad lol.

# Requirements

1. Make sure you have the GCC and G++ Compiler
2. Make sure you are running this on Windows

# Compile

```
gcc -c WS/send.c -o WS/send.o
gcc -c WS/start.c -o WS/start.o
g++ -c app.cpp -o app.o
g++ -c WS/server.cpp -o WS/server.o
g++ -o app app.o WS/send.o WS/server.o WS/start.o -lws2_32
```

You can use the batch file if you want to compile everything

# Usage

**Make sure your hmtl files are in the Site Folder, and open up app.cpp in an editor.**

You will be editing the Handle function. You can prolly already tell what you will do.
The resp variable is the path of your website. The send function will send the html data to the client.

```c++
void Handle(SOCKET client, char response[1024]) {
    std::string resp = parseReq(response);

    std::cout << resp;

    if (resp == "/") {
        SEND(client, "index.html");
    } else {
        SEND(client, "not_found.html");
    }
}
```

**Once you have everything setup you can now use the webserver which I don't recommend I made this for fun.**

# Images

![Screenshot 2025-03-03 221406](https://github.com/user-attachments/assets/6b6b4c40-5711-4b6b-94d5-38fddd2f9120)
