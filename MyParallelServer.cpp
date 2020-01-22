//
// Created by nizan on 21/01/2020.
//
#include <thread>
#include <unistd.h>
#include "MySerialServer.h"
#include "Server.h"
#include "MyParallelServer.h"


using namespace std;

int runServerParallel(int port, ClientHandler *client) {
/*
    int client_socket_server;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);


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

    int client_socket;
    int result = 0;
    while (!server_side::isRun) {
        fd_set rfds;
        struct timeval tv;
        tv.tv_sec = 120;//timout in seconds
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);

        //select-add it
        result = select(socketfd + 1, &rfds, (fd_set *) 0, (fd_set *) 0, &tv);
        if (result > 0) {
            // accepting a client
            int addrlen = sizeof(address);
            client_socket_server = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);

        } else {
            server_side::isRun = true;
            continue;
        }

        client->handleClient(socketfd);
        close(client_socket);
    }

    if (client_socket_server == -1) {
        cerr << "Error accepting" << endl;
        return -1;
    }


    close(socketfd);
    */
    //creates socket and checks if created
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD == -1) {
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }
    //binds socket to IP address (we want to listen to al IP)
    sockaddr_in address;
    address.sin_family = AF_INET;
    // any IP in IPV4
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    // Binds the socket to the given port at localhost.
    if (bind(socketFD, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }
    // listens to clients (1 can wait in the queue)
    if (listen(socketFD, 1) == -1) {
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }
    int client_socket;
    int result;
    // accepts clients
    while (!server_side::isRun) {
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(socketFD, &rfds);
        struct timeval tv;
        tv.tv_sec = (long)120;
        tv.tv_usec = 0;
        result = select(socketFD+1, &rfds, (fd_set*)0, (fd_set*)0, &tv);
        if (result > 0) {
            socklen_t addrlen = sizeof(sockaddr_in);
            client_socket = accept(socketFD, (struct sockaddr *) &address, &addrlen);
        }
        else {
            server_side::isRun = true;
            continue;
        }
        if (client_socket == -1) {
            return -4;
        }
        thread tn(runServerParallel, port, client);
        tn.detach();
        client->handleClient(client_socket);
        // close client socket
        close(client_socket);
    }
    // close server socket
    close(socketFD);
    return 0;
}


int MyParallelServer::open(int port, ClientHandler *client) {
    thread tc(runServerParallel, port, client);
    tc.join();

}


MyParallelServer::MyParallelServer() {}

MyParallelServer::~MyParallelServer() {

}


void MyParallelServer::stop() {
    return;

}
