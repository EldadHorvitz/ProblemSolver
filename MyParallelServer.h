//
// Created by nizan on 21/01/2020.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H


#include "Server.h"
#include "CasheManager.h"

class MyParallelServer : public server_side::Server {
public:
    MyParallelServer(){}

    int open(int port, ClientHandler *client,CasheManager* cm);

   // ~MyParallelServer() {}

    void stop() override;
};


#endif //EX4_MYPARALLELSERVER_H
