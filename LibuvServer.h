//
// Created by yaara on 19/08/2019.
//

#ifndef BENCHMARK_LIBUVSERVER_H
#define BENCHMARK_LIBUVSERVER_H


#include "Server.h"
#include "ServerFactory.h"

#include <memory>
#include <iostream>
#include <vector>
//#include <uvw.hpp>
class LibuvServer : public Server {
public:
    LibuvServer(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg);
    virtual int connect() override;
    virtual int accept()override;
    virtual int runInternal()override ;

//    void calc(uvw::Loop &loop, std::shared_ptr<uvw::TCPHandle> &Client)
//    void listen(uvw::Loop &loop);

private:
    static bool m_registerit;
    struct timeval start;
};



#endif //BENCHMARK_LIBUVSERVER_H

