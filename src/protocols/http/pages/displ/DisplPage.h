//
// Created by krzysiek on 4/3/19.
//

#ifndef HTTP_SERVER_DISPLPAGE_H
#define HTTP_SERVER_DISPLPAGE_H

#include "../IPage.h"
#include <string>
#include <map>
class DisplPage : public IPage{
public:
    std::string handle(const std::string& path) override;
    bool isMapOk(const std::map<std::string, std::string>& map);
};


#endif //HTTP_SERVER_DISPLPAGE_H
