set(http_sources
        Http.cpp
        pages/main/MainPage.cpp
        utils/html.cpp)
add_library(libHttp OBJECT ${http_sources})