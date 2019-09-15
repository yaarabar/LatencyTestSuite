//
// Created by yaara on 19/08/2019.
//

#include "ClientFactory.h"

std::map<ProtocolType , std::shared_ptr<Client>(*)(std::string hostIP, int port, int serversAmount, int clientsAmount,
                                                   int sizeOfMsg)> clientMap;

bool ClientFactory::registerClient(ProtocolType type, std::shared_ptr<Client>(*f)(std::string hostIP, int port, int serversAmount, int clientsAmount,
                                                                                  int sizeOfMsg)) {
    getMap().emplace(type, f);
    return true;
}

std::shared_ptr<Client> ClientFactory::getClient(ProtocolType type, std::string hostIP, int port, int serversAmount, int clientsAmount,
                                                 int sizeOfMsg) {
    auto it = getMap().find(type);
    if (it == getMap().end())
        return nullptr;
    return it->second(hostIP, port, serversAmount, clientsAmount, sizeOfMsg);
}
