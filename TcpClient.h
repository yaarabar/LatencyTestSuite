//
// Created by yaara on 19/08/2019.
//

#ifndef BENCHMARK_TCPCLIENT_H
#define BENCHMARK_TCPCLIENT_H

#include "ClientFactory.h"


class tcpClient: public client{
public:
    tcpClient() {};
    virtual int connect()override {return -1;} ;
    virtual int sendMsg()override {return -1;};
    virtual int disconnect()override{return -1;} ;

private:
    static bool m_registerit;
};
#endif //BENCHMARK_TCPCLIENT_H