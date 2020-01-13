//
// Created by nizan on 13/01/2020.
//

#include "MySerialServer.h"


using namespace std;

int MySerialServer::open(int port, ClientHandler client) {

    int client_socket_server;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);

    struct timeval tv;
    tv.tv_sec = 120;//timout in seconds
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);


    if (socketfd == -1) {
        //error
        cerr << "could not create a socket" << endl;
        return -1;
    }
    //bind socket to IP address
    //we first create the sockaddr obj.
    sockaddr_in address;//in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");//give me any IP allocated for my machine.
    address.sin_port = htons(port);
    //we need to convert our number
    //to a number that the network understands

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr << "could not bind socket to an IP" << endl;
        return -1;
    }

    if (listen(socketfd, 1) == -1) {
        cerr << "Error during listening command" << endl;
    }
    // accepting a client
    int addrlen = sizeof(address);
    client_socket_server = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);

    if (client_socket_server == -1) {
        cerr << "Error accepting" << endl;
        return -1;
    }


}
