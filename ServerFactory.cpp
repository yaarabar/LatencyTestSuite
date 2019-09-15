//
// Created by yaara on 19/08/2019.
//

#include "ServerFactory.h"

std::map<ProtocolType , std::shared_ptr<Server>(*)(std::string hostIP, int port, int serversAmount, int clientsAmount,
                                                   int sizeOfMsg)> serverMap;

bool ServerFactory::registerServer(ProtocolType type, std::shared_ptr<Server>(*f)(std::string hostIP, int port, int serversAmount, int clientsAmount,
                                                                                  int sizeOfMsg)) {
    getMap().emplace(type, f);
    return true;
}

std::shared_ptr<Server>
ServerFactory::getServer(ProtocolType type, std::string hostIP, int port, int serversAmount, int clientsAmount,
                         int sizeOfMsg) {
    auto it = getMap().find(type);
    if (it == getMap().end())
        return nullptr;
    return it->second(hostIP, port, serversAmount, clientsAmount, sizeOfMsg);
}
