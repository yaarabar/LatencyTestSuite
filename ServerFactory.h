//
// Created by yaara on 19/08/2019.
//

#ifndef BENCHMARK_SERVERFACTORY_H
#define BENCHMARK_SERVERFACTORY_H

#include "Server.h"
#include <memory>
#include <iostream>
#include <map>
class ServerFactory {

public:
    static std::shared_ptr<Server> getServer(ProtocolType type, std::string hostIP, int port, int serversAmount, int clientsAmount, int sizeOfMsg);
    static bool registerServer(ProtocolType type, std::shared_ptr<Server>(*)(std::string hostIP, int port, int serversAmount, int clientsAmount,
                                                                             int sizeOfMsg)); //ERASECOMMENT//for my understing: it looks like there is a pointer to an abstract class but since wew are buiding it via factory it will be pointing to the derived

private:
    static auto &getMap()
    {
        static std::map<ProtocolType , std::shared_ptr<Server>(*)(std::string hostIP, int port, int serversAmount, int clientsAmount,
                                                                  int sizeOfMsg)> serverMap;
        return serverMap;
    }
};

#endif //BENCHMARK_SERVERFACTORY_H
