#include <protocols/http/Http.hpp>
#include <server/server.h>

int main(int argc, char *argv[]) {
    try {
        Http http{};
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

