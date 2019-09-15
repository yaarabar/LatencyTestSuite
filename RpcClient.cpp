//
// Created by yaara on 19/08/2019.
//
#include "RpcClient.h"

bool RpcClient::m_registerit = ClientFactory::registerClient(RPC, [](std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)->std::shared_ptr<Client> {return std::make_shared<RpcClient>(hostIP, port, serversAmount, clientsAmount, sizeOfMsg);});

RpcClient::RpcClient(std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)
        : Client(hostIP, port, serversAmount, clientsAmount, sizeOfMsg), m_client("localhost", port), m_massage(MSG_SIZE)
{
    std::cout << "hay rpc Client!!!\n";

}

int RpcClient::sendMsg(Massage &massage) {
    m_client.async_call("getMsg");
    return 0;
}

int RpcClient::connect() {

    std::cout << "start RPC\n";
    gettimeofday(&start, nullptr);
    for (int i = 0; i < REQUESTS; ++i) {
        sendMsg(m_massage);
    }
    disconnect();
    pthread_exit(NULL);
    return 0;
}


int RpcClient::disconnect() {
    gettimeofday(&bwStart, nullptr);
    auto result = m_client.async_call("time", start.tv_sec, start.tv_usec);
    std::cout << "latency:\t" << result.get().as<std::string>() << " seconds\n";
    gettimeofday(&bwEnd, nullptr);
    auto bw = bwEnd.tv_sec - bwStart.tv_sec + bwEnd.tv_usec - bwStart.tv_usec;
    std::cout << "bandwidth:\t" << ((double)MSG_SIZE*REQUESTS/bw) << " bytes/sec\n";
    std::cout << "throughput:\t" << (double)REQUESTS/bw << " req/sec\n";

    return 0;
}

int RpcClient::runInternal() {

    std::thread t;
    t = std::thread(&RpcClient::connect, this);
    t.join();

    return 0;
}
