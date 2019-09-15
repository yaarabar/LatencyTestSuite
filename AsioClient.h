/*
 * 
 * 
 */

#ifndef BENCHMARK_ASIOCLIENT_H
#define BENCHMARK_ASIOCLIENT_H



#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <sys/time.h>
#include <vector>
#include <thread>
#include "Client.h"
#include "ClientFactory.h"
#include "Utilitis.h"
#include "ClientFactory.h"
#include <boost/asio.hpp>


using boost::asio::ip::tcp;

class AsioClient: public Client{
public:
    AsioClient(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg);
    virtual int connect() override;
    virtual int sendMsg(Massage &massage)override;
    virtual int disconnect()override;
    virtual int runInternal() override ;


private:
    boost::asio::io_context io_context;
    tcp::socket m_socket;
    tcp::resolver m_resolver;
    std::vector<std::thread> m_clientAmount;
    struct timeval start;
    Massage request;
    static bool m_registerit;
};


#endif //BENCHMARK_ASIOCLIENT_H
