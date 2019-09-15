//
// Created by yaara on 19/08/2019.
//

#include "AbstractClient.h"

AbstractClient::AbstractClient(std::string &hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)
        :IP(std::move(hostIP)), PORT(port), SERVERS(serversAmount), CLIENTS(clientsAmount), MSG_SIZE(sizeOfMsg), REQUESTS(1) {
    S_PORT = std::to_string(PORT);
}

int AbstractClient::run() {
    runInternal(); //todo::add here the stop method somehow

    return 0;
}