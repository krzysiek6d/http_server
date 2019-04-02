#pragma once
#include <functional>
#include <string>
class Http
{
    public:
        Http(std::function<void(const std::string&)> sendfunciton);
        void foo();
        void send(const std::string&);
        std::string http404(const std::string&);
    private:
        std::function<void(const std::string&)> send_;
};
