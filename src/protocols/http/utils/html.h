//
// Created by krzysiek on 4/3/19.
//

#ifndef HTTP_SERVER_HTML_H
#define HTTP_SERVER_HTML_H

#include <string>
namespace HTML {
    std::string tag(const std::string &name, const std::string &props = "", const std::string &content = "");
    std::string p(const std::string &text);
    std::string html(const std::string &content);
    std::string title(const std::string &tit);
    std::string body(const std::string &content);
    std::string form(const std::string &content);
    std::string select(const std::string &name, const std::string &content);
    std::string option(const std::string &value, const std::string &content);
    std::string submitButton(const std::string &text);
};

#endif //HTTP_SERVER_HTML_H
