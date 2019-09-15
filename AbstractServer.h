//
// Created by yaara on 19/08/2019.
//

#ifndef BENCHMARK_ABSTRACTSERVER_H
#define BENCHMARK_ABSTRACTSERVER_H

#include "Utilitis.h"
#include <iostream>


class AbstractServer {
public:
    AbstractServer(std::string &hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg);
    int run();
    virtual int runInternal() = 0;
    virtual int connect()=0;
    int stop();

protected:
    std::string IP; // the IP to be connected to, by defult is "localhost"
    int PORT;       // the port for the connection
    std::string S_PORT; //same port just write as a string
    int SERVERS;    //amount of servers which accepting messages
    int CLIENTS;    //
    int MSG_SIZE;
    int REQUESTS;
};


#endif //BENCHMARK_ABSTRACTSERVER_H
