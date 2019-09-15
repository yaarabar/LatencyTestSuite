//
// Created by yaara on 19/08/2019.
//

#include "RpcServer.h"
struct timeval RpcServer::start;
bool RpcServer::m_registerit = ServerFactory::registerServer(RPC, [](std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)->std::shared_ptr<Server> {return std::make_shared<RpcServer>(hostIP, port, serversAmount, clientsAmount, sizeOfMsg);});
int RpcServer::c  = 1;

RpcServer::RpcServer(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)
        : Server(hostIP, port, serversAmount, clientsAmount, sizeOfMsg) , srv(port) {
    std::cout << "hay rpc Server!!!\n";
    srv.bind("time", &RpcServer::calcTime);
    srv.bind("getMsg",&RpcServer::getMsg);
    c = CLIENTS;
}

int RpcServer::connect() {

    std::cout << "start RPC\n";
    srv.async_run(1);
    while(!stop())
        CLIENTS = c;

    pthread_exit(NULL);

    return 0;
}

std::string RpcServer::calcTime(int cliSec, int cliMSec)
{
    gettimeofday(&start, NULL);
    int sec = start.tv_sec - (cliSec);
    int usec = start.tv_usec -(cliMSec);
    std::string a = std::to_string(usec);
    if(a.size() < 6) {
        int size = 6 - a.size();
        a = "";
        for (int i = 0; i < size; ++i) {
            a+='0';
        }
    }
            
    std::string result = std::to_string(sec*1000000) + "." + a + std::to_string(usec);//todo::changet to correct calculation

    --c;

    return result;
}



int RpcServer::accept() {
    return 0;
}


int RpcServer::runInternal() {

    std::thread t;
    t = std::thread(&RpcServer::connect, this);
    t.join();


    return 0;
}
