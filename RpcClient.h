//
// Created by yaara on 19/08/2019.
//

#ifndef BENCHMARK_RPCCLIENT_H
#define BENCHMARK_RPCCLIENT_H

#include <rpc/client.h>
#include <iostream>
#include <sys/time.h>
#include <string>
#include <vector>
#include <thread>
#include "ClientFactory.h"
#include "Client.h"



class RpcClient: public Client{
public:
    RpcClient(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg);
    virtual int connect()override ;
    virtual int sendMsg(Massage &massage)override;
    virtual int disconnect()override;
    virtual int runInternal() override ;

private:
    Massage m_massage;
    static bool m_registerit;
    rpc::client m_client;
    struct timeval start;
    struct timeval bwStart;
    struct timeval bwEnd;
};

#endif //BENCHMARK_RPCCLIENT_H