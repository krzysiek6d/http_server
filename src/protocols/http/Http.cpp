#include "Http.hpp"
#include <sstream>
#include "pages/main/MainPage.h"
#include <iostream>
#include <regex>

std::string Http::handle(const std::string& request)
{
    auto path = getPath(request);
    if (path=="/favico.ico") {
        return http404("<html>hola hola, nie ma takiej strony 404!</html>");
    }
    if (path=="/") {
        return http202(MainPage().getMainPage());
    }
    auto parsedPath = parsePath(path);
    if (isMapOk(parsedPath))
    {
        // todo - execute here what you want
        std::cout << "EXECUTING" << std::endl;
        return http202(MainPage().getMainPage());
    }
    return http404("<html>hola hola, nie ma takiej strony 404!</html>");
}

std::map<std::string, std::string> Http::parsePath(std::string path)
{
    std::map<std::string, std::string> result;
    std::regex r("([a-zA-Z0-9]+)=([a-zA-Z0-9/_\\-]+)"); //todo add -
    std::smatch sm;
    while(std::regex_search(path, sm, r))
    {
        if (sm.size()==3)
            result[sm[1]] = sm[2];
        path = sm.suffix();
    }
    return result;
};

std::string Http::http404(const std::string& html)
{
    std::string msg = "HTTP/1.0 404 OK\r\n";
    msg += "Server: led executor\r\n";
    msg += "Content-Length: " + std::to_string(html.length()) + "\r\n\r\n";
    msg += html;
    return msg;
}

std::string Http::http202(const std::string& html)
{
    std::string msg = "HTTP/1.0 202 OK\r\n";
    msg += "Server: led executor\r\n";
    msg += "Content-Length: " + std::to_string(html.length()) + "\r\n\r\n";
    msg += html;
    return msg;
}

std::string Http::unescape(const std::string& path)
{
    static const std::regex r("(%2F)");
    return std::regex_replace(path, r, "/");
}

std::string Http::getPath(const std::string& request)
{
    std::stringstream s(request);
    std::string path;
    s >> path;
    s >> path;
    return unescape(path);
}

bool Http::isMapOk(const std::map<std::string, std::string>& map)
{
    return  map.size()==3 &&
            map.find("dn") != map.end() &&
            map.find("group") != map.end() &&
            map.find("message") != map.end();
}