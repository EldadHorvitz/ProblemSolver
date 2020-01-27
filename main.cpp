#include <iostream>
#include "MySerialServer.h"
#include "Server.h"
#include "MyTestClientHandler.h"
#include "CasheManager.h"
#include "MyParallelServer.h"

using namespace std;

int main(int args, char *argv[]) {

    CasheManager *cm = new CasheManager();
    ClientHandler *c = new MyTestClientHandler(cm);
    int port = 5600;
    try {
        port = stoi(argv[1]);
    } catch (exception e) {

    }
    server_side::Server *s = new MySerialServer();
    s->open(port, c, cm);


    return 0;
}
