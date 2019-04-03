//
// Created by krzysiek on 4/3/19.
//

#ifndef HTTP_SERVER_MAINPAGE_H
#define HTTP_SERVER_MAINPAGE_H

#include <string>
#include <vector>
#include "../IPage.h"

class MainPage : public IPage {
public:
    std::string handle(const std::string& path) override;
    void addLink(const std::string link);

private:
    std::vector<std::string> links;
};


#endif //HTTP_SERVER_MAINPAGE_H
