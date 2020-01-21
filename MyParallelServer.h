//
// Created by nizan on 21/01/2020.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H


#include "Server.h"

class MyParallelServer : public server_side::Server {
public:
    MyParallelServer();

    int open(int port, ClientHandler *client);

    virtual ~MyParallelServer();

    void stop() override;
};


#endif //EX4_MYPARALLELSERVER_H
