//
// Created by krzysiek on 4/3/19.
//

#ifndef HTTP_SERVER_HTTPHEADERS_H
#define HTTP_SERVER_HTTPHEADERS_H

#include <string>
#include <map>

class HttpHeaders {
public:
    static std::string http404(const std::string&);
    static std::string http202(const std::string& html);
    static std::string getPath(const std::string& request);
    static std::map<std::string, std::string> parsePath(std::string path);
    static std::string unescape(const std::string& );
    static std::string getPagePath(const std::string& request);
};


#endif //HTTP_SERVER_HTTPHEADERS_H
