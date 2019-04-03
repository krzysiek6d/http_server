//
// Created by krzysiek on 4/3/19.
//

#include "MainPage.h"
#include "MainPageRenderer.h"
#include "../../utils/HttpHeaders.h"

std::string MainPage::handle(const std::string& path)
{
    return HttpHeaders::http202(MainPageRenderer().getMainPage(links));
}

void MainPage::addLink(const std::string link)
{
    links.emplace_back(link);
}