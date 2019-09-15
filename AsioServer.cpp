//
// Created by yaara on 19/08/2019.
//

#include "AsioServer.h"


bool AsioServer::m_registerit = ServerFactory::registerServer(ASIO, [](std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)->std::shared_ptr<Server> {return std::make_shared<AsioServer>(hostIP, port, serversAmount, clientsAmount, sizeOfMsg);});


AsioServer::AsioServer(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)
        : Server(hostIP, port, serversAmount, clientsAmount, sizeOfMsg), m_acceptor(io_context, tcp::endpoint(tcp::v4(), PORT)), m_message(MSG_SIZE) {
}

int AsioServer::connect() {

    std::cout << "start ASIO\n";
    gettimeofday(&start, NULL);
    while (!stop())
        accept();

    io_context.run();
//    while (!stop()) //todo::check where to put that
//        accept();
    pthread_exit(NULL);

    return 0;
}

int AsioServer::accept() {

    m_acceptor.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket) {
                if (!ec) {
                    std::make_shared<Session>(std::move(socket), MSG_SIZE, REQUESTS)->start();
                    if(count < CLIENTS/SERVERS)//todo::check what instead!
                    {
                        accept();
                        ++count;
                    }
                    --CLIENTS;
                }
            });


    return 0;
}


int AsioServer::runInternal() {

    std::thread t;
    t = std::thread(&AsioServer::connect, this);
    t.join();

    return 0;
}

