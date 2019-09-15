//
// Created by yaara on 19/08/2019.
//

#ifndef BENCHMARK_ABSTRACTCLIENT_H
#define BENCHMARK_ABSTRACTCLIENT_H

#include "Utilitis.h"
#include <iostream>
#include <future>
#include <thread>

class AbstractClient {
public:
    AbstractClient(std::string &hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg);
    int run();
    virtual int runInternal() = 0;

protected:
    std::string IP;
    int PORT;
    std::string S_PORT;
    int SERVERS;
    int CLIENTS;
    int MSG_SIZE;
    int REQUESTS;
};


#endif //BENCHMARK_ABSTRACTCLIENT_H
