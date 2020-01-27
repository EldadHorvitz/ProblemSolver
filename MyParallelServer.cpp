//
// Created by nizan on 21/01/2020.
//
#include <thread>
#include <unistd.h>
#include "MySerialServer.h"
#include "Server.h"
#include "MyParallelServer.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include "vector"
#include "MyTestClientHandler.h"
#include "CasheManager.h"
#include "Cashe.h"

using namespace std;

//
// Created by avi on 25/01/2020.
//

#include "MyParallelServer.h"
#include "OA.h"

bool m_connected;
int MyParallelServer::open(int port, ClientHandler *ch) {

    int portNo, listenFd;
    struct sockaddr_in svrAdd, clntAdd;
    int connFd;
    vector<thread*> vec_thread;


    portNo = port;

    if((portNo > 65535) || (portNo < 2000))
    {
        cerr << "Please enter a port number between 2000 - 65535" << endl;
        return 0;
    }

    //create socket
    listenFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(listenFd < 0)
    {
        cerr << "Cannot open socket" << endl;
        return 0;
    }

    bzero((char*) &svrAdd, sizeof(svrAdd));

    svrAdd.sin_family = AF_INET;
    svrAdd.sin_addr.s_addr = INADDR_ANY;
    svrAdd.sin_port = htons(portNo);

    //bind socket
    if(bind(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0)
    {
        cerr << "Cannot bind" << endl;
        return 0;
    }

    listen(listenFd, 10);
    m_connected = true;
    int noThread = 0;

    while (m_connected)
    {
        socklen_t len = sizeof(clntAdd);

        cout << "Listening" << endl;
        struct timeval tv{};
        tv.tv_sec = 120;
        setsockopt(listenFd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
        connFd = accept(listenFd, (struct sockaddr *)&clntAdd, &len);

        if (connFd < 0)
        {
            cerr << "Cannot accept connection" << endl;
            return 0;
        }
        else
        {
            cout << "Connection successful" << endl;
        }

        MyTestClientHandler* ch = new MyTestClientHandler();
        //thread *t_var_command = new thread(&MyClientHandler::handleClient, ref(ch), connFd);
       // ClientHandler* clientHandler = new MyTestClientHandler(new OA(new BestFirstSearch<string>), new FileCacheManager);
        //ClientHandler* clientHandler = ch->clone();
        thread *t_ch = new thread(&ClientHandler::handleClient, ref(ch), connFd);
        vec_thread.push_back(t_ch);
        noThread++;
    }

    for (int i = 0; i < vec_thread.size(); i++)
    {
        vec_thread[i]->join();
    }
}

void MyParallelServer::stop() {
    m_connected = false;
}

