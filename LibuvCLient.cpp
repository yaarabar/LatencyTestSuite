//
// Created by yaara on 19/08/2019.
//
#include "LibuvCLient.h"

bool LibuvCLient::m_registerit = ClientFactory::registerClient(LIBUV, [](std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)->std::shared_ptr<Client> {return std::make_shared<LibuvCLient>(hostIP, port, serversAmount, clientsAmount, sizeOfMsg);});

LibuvCLient::LibuvCLient(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)
        : Client(hostIP, port, serversAmount, clientsAmount, sizeOfMsg)
{

}

int LibuvCLient::connect() {
//    tcp->connect(IP, PORT);
// sendMsg();
    std::cout << "start LIBUV\n";
    return 0;
}

int LibuvCLient::sendMsg(Massage &massage) {
//    auto tcp = loop.resource<uvw::TCPHandle>();
//    tcp->on<uvw::ErrorEvent>([](const uvw::ErrorEvent & er, uvw::TCPHandle &) { exit(er.code()); });
//
//    gettimeofday(&start, NULL);
//    std::cout << start.tv_sec << " " << start.tv_usec<< "\n";
//
//    tcp->once<uvw::ConnectEvent>([](const uvw::ConnectEvent &, uvw::TCPHandle &tcp) {
//
//        char* a=(char*)malloc(MSG_SIZE);
//        auto dataWrite = std::unique_ptr<char[]>(strdup(a));
//        for (int i=0; i< REQUESTS; ++i)
//            tcp.write(std::move(dataWrite), MSG_SIZE);
//        tcp.close();
//        free(a);
//    });
    return 0;
}

int LibuvCLient::disconnect() {
    return 0;
}

int LibuvCLient::runInternal() {
//    auto loop = uvw::Loop::getDefault();
//    connect(*loop);
//    loop->run();

    return 0;
}



/*already been copied! need to check if working
 *
 *
 * void LibuvCLient::conn(uvw::Loop &loop, int port) {
//    auto tcp = loop.resource<uvw::TCPHandle>();
//    tcp->on<uvw::ErrorEvent>([](const uvw::ErrorEvent & er, uvw::TCPHandle &) { exit(er.code()); });
//
//    gettimeofday(&start, NULL);
//    std::cout << start.tv_sec << " " << start.tv_usec<< "\n";
//
//    tcp->once<uvw::ConnectEvent>([](const uvw::ConnectEvent &, uvw::TCPHandle &tcp) {
//
//        char* a=(char*)malloc(SIZEOFMES);
//        auto dataWrite = std::unique_ptr<char[]>(strdup(a));
//        for (int i=0; i< NUMOFREQ; ++i)
//            tcp.write(std::move(dataWrite), SIZEOFMES);
//        tcp.close();
//        free(a);
//    });
//    tcp->connect("localhost", port);

}
 */



