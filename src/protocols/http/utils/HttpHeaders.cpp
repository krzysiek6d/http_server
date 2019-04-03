//
// Created by krzysiek on 4/3/19.
//

#include "HttpHeaders.h"
#include <regex>
#include <sstream>

std::map<std::string, std::string> HttpHeaders::parsePath(std::string path)
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

std::string HttpHeaders::http404(const std::string& html)
{
    std::string msg = "HTTP/1.0 404 OK\r\n";
    msg += "Server: led executor\r\n";
    msg += "Content-Length: " + std::to_string(html.length()) + "\r\n\r\n";
    msg += html;
    return msg;
}

std::string HttpHeaders::http202(const std::string& html)
{
    std::string msg = "HTTP/1.0 202 OK\r\n";
    msg += "Server: led executor\r\n";
    msg += "Content-Length: " + std::to_string(html.length()) + "\r\n\r\n";
    msg += html;
    return msg;
}

std::string HttpHeaders::unescape(const std::string& path)
{
    static const std::regex r("(%2F)");
    return std::regex_replace(path, r, "/");
}

std::string HttpHeaders::getPath(const std::string& request)
{
    std::stringstream s(request);
    std::string path;
    s >> path;
    s >> path;
    return HttpHeaders::unescape(path);
}

std::string HttpHeaders::getPagePath(const std::string& request)
{
    if (request.length()==0)
        return "";
    auto resource = HttpHeaders::getPath(request);
    std::regex re("/+");
    std::string filePath = std::regex_replace(resource, re, "/");
    auto questionMarkItr = std::find(filePath.begin(), filePath.end(), '?');
    if (questionMarkItr == filePath.end())
    {
        auto hashtagItr = std::find(filePath.begin(), filePath.end(), '?');
        return std::string(filePath.begin()+1, hashtagItr);
    }
    return std::string(filePath.begin()+1, questionMarkItr);
}