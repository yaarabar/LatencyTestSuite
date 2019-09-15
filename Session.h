//
// Created by yaara on 02/09/2019.
//

#ifndef BENCHMARK_SESSION_H
#define BENCHMARK_SESSION_H

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <sys/time.h>
//#include "AbstractClient.h"

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(tcp::socket socket, int messageSize, int requestAmount);
    void start();

private:
    void do_read();

    tcp::socket socket_;
    int msgSize;
    int requests;
    char* m_data;
    int j = 0;
};


#endif //BENCHMARK_SESSION_H
