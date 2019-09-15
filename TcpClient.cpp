//
// Created by yaara on 19/08/2019.
//
#include "TcpClient.h"

bool tcpClient::m_registerit = clientFactory::registerClient(TCP, []()->std::unique_ptr<client> {return std::make_unique<tcpClient>();});
