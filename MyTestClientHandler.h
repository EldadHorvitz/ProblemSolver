//
// Created by nizan on 14/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include <mutex>
static std::mutex m2;
class MyTestClientHandler : public ClientHandler {
public:
    void handleClient(int socket) override;

    virtual ~MyTestClientHandler();
};


#endif //EX4_MYTESTCLIENTHANDLER_H
