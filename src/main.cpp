#include <protocols/http/Http.hpp>
#include <server/server.h>
#include <protocols/http/pages/displ/DisplPage.h>
int main(int argc, char *argv[]) {
    try {
        Http http{};
        DisplPage displPage{};
        http.registerPage("displ", &displPage);
        boost::asio::io_context io_context;
        server s(io_context, 8080);
        s.setOnMessageHandler(std::bind(&Http::handle, &http, std::placeholders::_1));
        io_context.run();
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

