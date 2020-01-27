//
// Created by nizan on 14/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include <mutex>
#include "CasheManager.h"
static std::mutex m2;
class MyTestClientHandler : public ClientHandler {
private:
//    CasheManager* cm;
public:
    void handleClient(int socket) override;
    MyTestClientHandler();
};


#endif //EX4_MYTESTCLIENTHANDLER_H
