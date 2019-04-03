#include "Http.hpp"
#include "protocols/http/pages/main/MainPageRenderer.h"
#include <iostream>
#include "utils/HttpHeaders.h"
std::string Http::handle(const std::string& request)
{
    auto path = HttpHeaders::getPath(request);
    if (path=="/favico.ico") {
        return HttpHeaders::http404("<html>hola hola, nie ma takiej strony 404!</html>");
    }
    if (path=="/") {
        return mainPage.handle(path);
    }
    auto parsedPath = HttpHeaders::getPagePath(request);
    if (pages.find(parsedPath) != pages.end())
    {
        return pages[parsedPath]->handle(path);
    }
    return HttpHeaders::http404("<html>hola hola, nie ma takiej strony 404!</html>");
}

void Http::registerPage(const std::string& pathPrefix, IPage* page)
{
    pages[pathPrefix] = page;
    mainPage.addLink(pathPrefix);
}

