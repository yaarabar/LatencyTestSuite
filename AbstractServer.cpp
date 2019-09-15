//
// Created by yaara on 19/08/2019.
//

#include "AbstractServer.h"


AbstractServer::AbstractServer(std::string &hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg)
        :IP(std::move(hostIP)), PORT(port), SERVERS(serversAmount), CLIENTS(clientsAmount), MSG_SIZE(sizeOfMsg), REQUESTS(1) {
    S_PORT = std::to_string(PORT);
}

int AbstractServer::run() {

    runInternal(); //todo::add here the stop method somehow
    return 0;
}

int AbstractServer::stop() {
    if(CLIENTS > 0)
        return 0;
    else
        return 1;
}


