//
// Created by yaara on 19/08/2019.
//

#include "AsioClient.h"
using::std::string;


//register the asio Server to the factory map
bool AsioClient::m_registerit = ClientFactory::registerClient(ASIO,
                                                              [](std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)->std::shared_ptr<Client> {return std::make_shared<AsioClient>(hostIP, port, serversAmount, clientsAmount, sizeOfMsg);});

//constractor of the asio Client. starting the Client and the socket
AsioClient::AsioClient(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)
    : Client(hostIP, port, serversAmount, clientsAmount, sizeOfMsg), m_socket(io_context), m_resolver(io_context), request(MSG_SIZE) {
}

//connect to the asio Server to send mwssages
int AsioClient::connect() {
    boost::asio::connect(m_socket, m_resolver.resolve("localhost", S_PORT));
    S_PORT = std::to_string((PORT) % SERVERS);
    gettimeofday(&start, NULL);
    sendMsg(request);
    disconnect();
    pthread_exit(NULL);
}

//disconnect from the asio , here need to calculate the latency and rest parameters
int AsioClient::disconnect() {
    return 0;
}

//write messages of the baffer for the Server to read
int AsioClient::sendMsg(Massage &massage) {
    for (int i = 0; i < REQUESTS; ++i) {
        boost::asio::write(m_socket, boost::asio::buffer(massage.get(), MSG_SIZE)); //todo::need to work!
    }
}

//create a thread to run the Client
int AsioClient::runInternal() {
    std::thread t;
    t = std::thread(&AsioClient::connect, this);
    t.join();

    return 0;
}
