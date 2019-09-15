//
// Created by yaara on 19/08/2019.
//

#ifndef BENCHMARK_RPCSERVER_H
#define BENCHMARK_RPCSERVER_H


#include "Server.h"
#include "ServerFactory.h"
#include "rpc/server.h"
#include <string>
#include <iostream>
#include <sys/time.h>
#include <thread>

class RpcServer : public Server {
public:
    RpcServer(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg);
    virtual int connect() override;
    virtual int accept() override;
    std::string static calcTime(int cliSec, int cliMSec);
    void static getMsg(const std::string s) { std::cout << "hello\n"; };
    virtual int runInternal() override ;

private:
    static bool m_registerit;
    rpc::server srv ;
    static struct timeval start;
    static int c;
};


#endif //BENCHMARK_RPCSERVER_H
