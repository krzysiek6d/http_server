//
// Created by krzysiek on 4/3/19.
//
#include <string>
#include "html.h"
namespace HTML {
    std::string tag(const std::string &name, const std::string &props, const std::string &content) {
        return "<" + name + " " + props + ">" + content + "</" + name + ">";
    }

    std::string p(const std::string &text) {
        return tag("p", "", text);
    }

    std::string html(const std::string &content) {
        return tag("html", "", content);
    }

    std::string title(const std::string &tit) {
        return tag("title", "", tit);
    }

    std::string body(const std::string &content) {
        return tag("body", "", content);
    }

    std::string form(const std::string &content) {
        return tag("form", R"(action="" method="get")", content);
    }

    std::string select(const std::string &name, const std::string &content) {
        return tag("select", R"(name=")" + name + R"(")", content);
    }

    std::string option(const std::string &value, const std::string &content) {
        return tag("option", R"(value=")" + value + R"(")", content);
    }

    std::string submitButton(const std::string &text) {
        return R"(<input type="submit" value=")" + text + R"("\>)";
    }
};
