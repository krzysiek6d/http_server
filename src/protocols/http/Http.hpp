#pragma once
#include <functional>
#include <string>
#include <map>

class Http
{
    public:
        std::string handle(const std::string& request);
        std::string http404(const std::string&);
        std::string http202(const std::string& html);
        std::string getPath(const std::string& request);
        std::map<std::string, std::string> parsePath(std::string path);
        bool isMapOk(const std::map<std::string, std::string>&);
        std::string unescape(const std::string& );
};
