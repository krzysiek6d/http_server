set(http_sources
        Http.cpp
        pages/main/MainPageRenderer.cpp
        utils/html.cpp pages/IPage.h utils/HttpHeaders.cpp utils/HttpHeaders.h pages/main/MainPage.cpp pages/main/MainPage.h pages/displ/DisplPage.cpp pages/displ/DisplPage.h pages/displ/DisplPageRenderer.cpp pages/displ/DisplPageRenderer.h)
add_library(libHttp OBJECT ${http_sources})