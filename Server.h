//
// Created by talya on 19/08/2019.
//

#ifndef BENCHMARK_SERVER_H
#define BENCHMARK_SERVER_H


#include "AbstractServer.h"
#include "Utilitis.h"
#include "Massage.h"
#include <boost/asio.hpp>



class Server : public AbstractServer{

    using AbstractServer::AbstractServer;
    virtual int connect()=0;
    virtual int accept()=0;
};


#endif //BENCHMARK_SERVER_H
