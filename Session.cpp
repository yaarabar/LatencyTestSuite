//
// Created by yaara on 02/09/2019.
//

#include "Session.h"

Session::Session(tcp::socket socket, int messageSize, int requestAmount)
        : socket_(std::move(socket)), msgSize(messageSize), requests(requestAmount) {
}

void Session::start() {
    do_read();
}

void Session::do_read() {
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(m_data, msgSize),[this, self](boost::system::error_code ec, std::size_t length) {
        if(j < requests)
        {
            do_read(); //todo::end the reqursia!!! everywhere!
            ++j;
        }
    });
}
