//
// Created by yaara on 19/08/2019.
//

#ifndef BENCHMARK_TCPSERVER_H
#define BENCHMARK_TCPSERVER_H

#include "ServerFactory.h"
#include "Server.h"

class tcpServer : public server {
public:
    tcpServer(){};
    virtual int connect() override {return -1;};
    virtual int accept()override {return -1;};

private:
    static bool m_registerit;
};


#endif //BENCHMARK_TCPSERVER_H
