//
// Created by yaara on 19/08/2019.
//
#pragma once
#ifndef BENCHMARK_CLIENTFACTORY_H
#define BENCHMARK_CLIENTFACTORY_H

#include <iostream>
#include "Client.h"
#include <memory>
#include <map>
class ClientFactory {

public:
    std::shared_ptr<Client> static getClient(ProtocolType type, std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg);
    bool static registerClient(ProtocolType , std::shared_ptr<Client>(*)(std::string hostIP, int port, int serversAmount, int clientsAmount,
                                                                         int sizeOfMsg)); //ERASECOMMENT//for my understing: it looks like there is a pointer to an abstract class but since wew are buiding it via factory it will be pointing to the derived
private:
    static auto &getMap()
    {
        static std::map<ProtocolType , std::shared_ptr<Client>(*)(std::string hostIP, int port, int serversAmount, int clientsAmount,
                                                                  int sizeOfMsg)> clientMap;
        return clientMap;
    }
};


#endif //BENCHMARK_CLIENTFACTORY_H
