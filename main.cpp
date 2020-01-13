#include <iostream>
#include "MySerialServer.h"
#include "Server.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "this is ex4" << std::endl;

    MySerialServer *f = new MySerialServer();
    ClientHandler *c = new ClientHandler();
    f->open(5400, *c);

    return 0;
}
