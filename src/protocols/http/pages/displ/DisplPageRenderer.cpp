//
// Created by krzysiek on 4/3/19.
//

#include "DisplPageRenderer.h"
#include <protocols/http/utils/html.h>
std::string DisplPageRenderer::getPage(const std::string& message) {
    using namespace HTML;
    return html(
                    title("hello") +
                    body(
                            p("LED EXECUTOR ON DISP_L OBJECTS") +
                            p(message) +
                            form(
                                    select("dn",
                                           option("/MRBTS-1/SMOD_L-1", "/MRBTS-1/SMOD_L-1") +
                                           option("/MRBTS-1/BBMOD_L-1", "/MRBTS-1/BBMOD_L-1") +
                                           option("/MRBTS-1/BBMOD_L-2", "/MRBTS-1/BBMOD_L-2")
                                    ) +
                                    select("group",
                                           option("0", "EGroup_1") +
                                           option("1", "EGroup_2") +
                                           option("2", "EGroup_3")
                                    ) +
                                    select("message",
                                           option("0", "EMessage_1") +
                                           option("1", "EMessage_2") +
                                           option("2", "EMessage_3")
                                    ) +
                                    submitButton("execute")
                            )

                    )
            );
}