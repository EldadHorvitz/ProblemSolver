//
// Created by eldad on 13/01/2020.
//


#include <unistd.h>
#include "Server.h"

#define PORT 8081
using namespace std;

void Server::stop() {
    close(this->socketfd); //closing the listening socket
}