#include <iostream>
#include "MySerialServer.h"
#include "Server.h"
#include "MyTestClientHandler.h"

using namespace std;

int main(int args, char *argv[]) {


    ClientHandler *c = new MyTestClientHandler();
    int port = stoi(argv[1]);
    server_side::Server *s = new MySerialServer();
    s->open(port, c);


    return 0;
}
