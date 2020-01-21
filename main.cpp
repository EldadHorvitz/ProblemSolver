#include <iostream>
#include "MySerialServer.h"
#include "Server.h"
#include "MyTestClientHandler.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "this is ex4" << std::endl;

    ClientHandler *c = new MyTestClientHandler();
    int port = 5060;
    server_side::Server *s = new MySerialServer();
    s->open(port, c);


    return 0;
}
