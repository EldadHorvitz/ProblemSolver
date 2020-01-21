//
// Created by nizan on 21/01/2020.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H


#include "Server.h"

class MyParallelServer : public server_side::Server {
public:
    int open(int port, ClientHandler *client);
};


#endif //EX4_MYPARALLELSERVER_H
