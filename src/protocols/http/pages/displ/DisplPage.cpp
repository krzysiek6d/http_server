//
// Created by krzysiek on 4/3/19.
//

#include "DisplPage.h"
#include "DisplPageRenderer.h"
#include "../../utils/HttpHeaders.h"

std::string DisplPage::handle(const std::string& path)
{
    auto arguments = HttpHeaders::parsePath(path);
    if (arguments.size() == 0)
        return HttpHeaders::http202(DisplPageRenderer().getPage("Aby egzekucje wybierz elementy z listy i kliknij execute"));
    else if (isMapOk(arguments)) {
        std::string msg = "Wykonano egzekucje DISP_L na <br /> dn: " + arguments["dn"] + "<br />"
            "Sprawdz wynik na BTSie lub w infomodelu. Aby ponowic egzekucje wybierz elementy z listy i kliknij execute";
        return HttpHeaders::http202(DisplPageRenderer().getPage(msg));
    }
    else
        return HttpHeaders::http404("<html>strona nie istnieje</html>");
}

bool DisplPage::isMapOk(const std::map<std::string, std::string>& map)
{
    return  map.size()==3 &&
            map.find("dn") != map.end() &&
            map.find("group") != map.end() &&
            map.find("message") != map.end();
}