//
// Created by yaara on 19/08/2019.
//

#ifndef BENCHMARK_ASIOSERVER_H
#define BENCHMARK_ASIOSERVER_H

#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <sys/time.h>
#include <vector>
#include <thread>
#include <boost/asio.hpp>
#include "Server.h"
#include "ServerFactory.h"
#include "Session.h"
#include "Massage.h"

using::std::string;
using boost::asio::ip::tcp;


class AsioServer: public Server{
public:
    AsioServer(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg);
    virtual int connect() override;
    virtual int accept()override;
    virtual int runInternal() override ;


private:
    struct timeval start;
    boost::asio::io_context io_context;
    tcp::acceptor m_acceptor;
    Massage m_message;
    int count = 0;
    static bool m_registerit;
//    std::shared_ptr<Session> m_session;
};


#endif //BENCHMARK_ASIOSERVER_H
