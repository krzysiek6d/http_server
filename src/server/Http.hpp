#pragma once
#include <functional>
#include <string>
#include <map>
class Http
{
    public:
        Http(std::function<void(const std::string&)> sendfunciton, const std::string& request);
        void handle();
        void send(const std::string&);
        std::string http404(const std::string&);
        std::string http202(const std::string& html);
        std::string getPath();
        std::map<std::string, std::string> parsePath(std::string path);
        bool isMapOk(const std::map<std::string, std::string>&);
        std::string unescape(const std::string& );

private:
        std::function<void(const std::string&)> send_;
        std::string request;
};
