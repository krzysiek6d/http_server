#pragma once
#include <functional>
#include <string>
#include <map>
#include "pages/IPage.h"
#include <memory>
#include "pages/main/MainPage.h"
class Http
{
    public:
        std::string handle(const std::string& request);
        void registerPage(const std::string& pathPrefix, IPage* page);
        bool isMapOk(const std::map<std::string, std::string>&);

private:
    std::map<std::string, IPage*> pages;
    MainPage mainPage;
};
