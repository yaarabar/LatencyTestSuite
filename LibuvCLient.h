//
// Created by yaara on 19/08/2019.
//

#ifndef BENCHMARK_LIBUVCLIENT_H
#define BENCHMARK_LIBUVCLIENT_H

#include "ClientFactory.h"
//#include <uvw.hpp>
#include <memory>
#include <cstring>
#include <sys/time.h>
#include <iostream>
#include <string>
#include <vector>

class LibuvCLient : public Client{
public:
    LibuvCLient(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg);
    virtual int connect()override;
    virtual int sendMsg(Massage& massage)override;
    virtual int disconnect()override;
    virtual int runInternal() override ;

//    void conn(uvw::Loop &loop, int port)

private:
    static bool m_registerit;
    struct timeval start;
};


#endif //BENCHMARK_LIBUVCLIENT_H
