//
// Created by nizan on 14/01/2020.
//

#include <unistd.h>
#include "MyTestClientHandler.h"

using namespace std;

void MyTestClientHandler::handleClient(int socket) {
    //reading from client
    char buffer[1024] = {0};
    while (1) {
        read(socket, buffer, 1024);
        cout << buffer;
    }


}
