//
// Created by krzysiek on 4/3/19.
//

#include <protocols/http/utils/html.h>
#include "MainPageRenderer.h"
#include <vector>

std::string MainPageRenderer::getMainPage(std::vector<std::string> subpages) {
    using namespace HTML;
    std::string pages{};
    for (auto&& subpage : subpages)
        pages += link(subpage, subpage);

    return html(
            title("strona glowna") +
            body(
                    p("Strona glowna") +
                    pages
                    )
            );
}
