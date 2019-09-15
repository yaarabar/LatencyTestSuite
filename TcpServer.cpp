//
// Created by yaara on 19/08/2019.
//

#include "TcpServer.h"

bool tcpServer::m_registerit = serverFactory::registerServer(TCP, []()->std::unique_ptr<server> {return std::make_unique<tcpServer>();});