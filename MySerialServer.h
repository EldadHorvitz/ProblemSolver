//
// Created by nizan on 13/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public server_side::Server {
public:
    int open(int port, ClientHandler *client) ;

private:
};


#endif //EX4_MYSERIALSERVER_H
