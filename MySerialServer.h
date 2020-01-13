//
// Created by nizan on 13/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public Server {
public:
    int open(int port, ClientHandler client) override;

private:

public:


};


#endif //EX4_MYSERIALSERVER_H
