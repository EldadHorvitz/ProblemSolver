#include <iostream>
#include "MySerialServer.h"
#include "Server.h"
#include "MyTestClientHandler.h"
#include "CasheManager.h"
#include "MyParallelServer.h"

using namespace std;

int main(int args, char *argv[]) {

   // CasheManager* cm =new CasheManager();
    ClientHandler *c = new MyTestClientHandler();
    int port = 5600;
    try {
        port = stoi(argv[1]);
    } catch (exception e) {

    }
    server_side::Server *s = new MyParallelServer();
    s->open(port, c);


    return 0;
}
