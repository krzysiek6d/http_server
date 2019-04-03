//
// Created by krzysiek on 4/3/19.
//

#ifndef HTTP_SERVER_IPAGE_H
#define HTTP_SERVER_IPAGE_H

#include <string>
class IPage
{
public:
    virtual std::string handle(const std::string& path) = 0;
};
#endif //HTTP_SERVER_IPAGE_H
