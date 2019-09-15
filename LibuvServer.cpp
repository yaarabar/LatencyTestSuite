//
// Created by yaara on 19/08/2019.
//

#include "LibuvServer.h"

bool LibuvServer::m_registerit = ServerFactory::registerServer(LIBUV, [](std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)->std::shared_ptr<Server> {return std::make_shared<LibuvServer>(hostIP, port, serversAmount, clientsAmount, sizeOfMsg);});

int LibuvServer::connect() {
    std::cout << "start LIBUV\n";

//    std::shared_ptr<uvw::TCPHandle> tcp = loop.resource<uvw::TCPHandle>();
//    tcp->on<uvw::ErrorEvent>([](const uvw::ErrorEvent & er, uvw::TCPHandle &) { exit(er.code()); });
//
//    tcp->on<uvw::ListenEvent>([](const uvw::ListenEvent &, uvw::TCPHandle &srv) {
//        auto calc_loop = uvw::Loop::getDefault();
//        std::shared_ptr<uvw::TCPHandle> Client = srv.loop().resource<uvw::TCPHandle>();
//
//        Client->once<uvw::EndEvent>([](const uvw::EndEvent &, uvw::TCPHandle &Client) {
//            Client.close();
//        });
//
//        Client->on<uvw::DataEvent>([](const uvw::DataEvent & data, uvw::TCPHandle &) {});
//        srv.accept(*Client);
//        calc(*calc_loop, Client);
//        calc_loop->run();
//
//    });
//    tcp->bind("localhost", port);
//    tcp->listen();

    return 0;
}

int LibuvServer::accept() {
//    for (int i = 0; i <REQUESTS ; ++i)
//        Client->read();
//
//    gettimeofday(&start, NULL);
//    std::cout << start.tv_sec << " " << start.tv_usec << std::endl;
    return 0;
}

LibuvServer::LibuvServer(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)
        : Server(hostIP, port, serversAmount, clientsAmount, sizeOfMsg) {

}

int LibuvServer::runInternal() {

//    auto loop = uvw::Loop::getDefault();
//    connect(*loop);
//    loop->run();

    return 0;
}

/*
 *
void LibuvServer::calc(uvw::Loop &loop, std::shared_ptr<uvw::TCPHandle> &Client)
{
    for (int i = 0; i <NUMOFREQ ; ++i)
        Client->read();

    gettimeofday(&start, NULL);
    std::cout << start.tv_sec << " " << start.tv_usec << std::endl;
}


void LibuvServer::listen(uvw::Loop &loop) {
//    std::shared_ptr<uvw::TCPHandle> tcp = loop.resource<uvw::TCPHandle>();
//    tcp->on<uvw::ErrorEvent>([](const uvw::ErrorEvent & er, uvw::TCPHandle &) { exit(er.code()); });
//
//    tcp->on<uvw::ListenEvent>([](const uvw::ListenEvent &, uvw::TCPHandle &srv) {
//        auto calc_loop = uvw::Loop::getDefault();
//        std::shared_ptr<uvw::TCPHandle> Client = srv.loop().resource<uvw::TCPHandle>();
//
//        Client->once<uvw::EndEvent>([](const uvw::EndEvent &, uvw::TCPHandle &Client) {
//            Client.close();
//        });
//
//        Client->on<uvw::DataEvent>([](const uvw::DataEvent & data, uvw::TCPHandle &) {});
//        srv.accept(*Client);
//        calc(*calc_loop, Client);
//        calc_loop->run();
//
//    });
//
//    tcp->bind("localhost", port);
//    tcp->listen();
}
 */




