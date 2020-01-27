//
// Created by eldad on 13/01/2020.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H

//#include <bits/socket.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include "ClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "CasheManager.h"

namespace server_side {
    class Server {
    public:
        virtual int open(int port, ClientHandler *client) = 0;

        virtual void stop() = 0;

        virtual ~Server() {

        }

    };

    __attribute__((unused))  static bool isRun = false;

}

#endif //EX4_SERVER_H
