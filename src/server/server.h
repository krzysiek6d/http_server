//
// Created by krzysiek on 4/3/19.
//

#ifndef HTTP_SERVER_SERVER_H
#define HTTP_SERVER_SERVER_H

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class session
        : public std::enable_shared_from_this<session>
{
public:
    session(tcp::socket socket, std::function<std::string(const std::string&)> onMessage)
            : socket_(std::move(socket)), onMessage(onMessage)
    {
    }

    void start()
    {
        do_read();
    }

    void send(const std::string& message)
    {
        auto s = std::make_shared<std::string>(message);
        auto self(this->shared_from_this());
        boost::asio::async_write(socket_, boost::asio::buffer(*s), [this, self](boost::system::error_code ec, std::size_t /*len*/)
        {
        });
    }

private:
    void do_read()
    {
        auto self(this->shared_from_this());
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
                                [this, self](boost::system::error_code ec, std::size_t length)
                                {
                                    if (!ec)
                                    {
                                        if (onMessage)
                                            send(onMessage(std::string(data_)));
                                        socket_.close(); // TODO add policy if close here or not
                                    }
                                });
    }
    tcp::socket socket_;
    std::function<std::string(const std::string&)> onMessage;
    enum { max_length = 1024 };
    char data_[max_length];
};


class server
{
public:
    server(boost::asio::io_context& io_context, short port)
            : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
    {
        do_accept();
    }
    
    void setOnMessageHandler(std::function<std::string(const std::string)> sendHandler)
    {
        onMessage = sendHandler;
    }


private:
    void do_accept()
    {
        acceptor_.async_accept(
                [this](boost::system::error_code ec, tcp::socket socket)
                {
                    if (!ec)
                    {
                        std::make_shared<session>(std::move(socket), onMessage)->start();
                    }

                    do_accept();
                });
    }

    tcp::acceptor acceptor_;
    std::function<std::string(const std::string&)> onMessage;
};

#endif //HTTP_SERVER_SERVER_H
