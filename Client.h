//
// Created by talya on 19/08/2019.
//
#pragma once
#ifndef BENCHMARK_CLIENT_H
#define BENCHMARK_CLIENT_H


#include "AbstractClient.h"
#include "Utilitis.h"
#include "Massage.h"

class Client : public AbstractClient {
public:
    using AbstractClient::AbstractClient;

    virtual int connect()=0;
    virtual int sendMsg(Massage &massage)=0;
    virtual int disconnect()=0;

//protected:
   // Massage m_massage;
    //int SIZEOFMSG;
  //  int CLIENTS;
   // int REQUESTS;
    //int PORT = 12000;
};


#endif //BENCHMARK_CLIENT_H
