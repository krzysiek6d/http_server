#include "Http.hpp"

Http::Http(std::function<void(const std::string&)> sendfunction)
{
    send_ = sendfunction;
    send(http404("<html><body>not found</body></html>"));
}

void Http::send(const std::string& message)
{
    if (send_)
        send_(message);
}

std::string Http::http404(const std::string& html)
{
    std::string msg = "HTTP/1.0 404 OK\r\n";
    msg += "Server: coding_dojo\r\n";
    msg += "Content-Length: " + std::to_string(html.length()) + "\r\n\r\n";
    msg += html;
    return msg;
}

void Http::foo()
{

}

