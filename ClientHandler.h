//
// Created by eldad on 13/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include "ClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class ClientHandler {
private:

public:
    virtual void handleClient(int socket) = 0;

};


#endif //EX4_CLIENTHANDLER_H
