//
// Created by nizan on 14/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {
public:
    void handleClient(int socket) override;


};


#endif //EX4_MYTESTCLIENTHANDLER_H
