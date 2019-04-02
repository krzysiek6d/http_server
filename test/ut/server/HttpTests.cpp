//
// Created by pawluch on 3/7/19.
//
#include <gtest/gtest.h>
#include <server/Http.hpp>

TEST(http_test, should_get_proper_path)
{
    std::vector<std::string> consumedData;
    auto send = [&](const std::string& message)
    {
        consumedData.push_back(message);
    };
    auto http = Http(send);
    http.send("hello!");
    EXPECT_EQ(2u, consumedData.size());
    EXPECT_EQ("HTTP/1.0 404 OK\r\nServer: coding_dojo\r\nContent-Length: 35\r\n\r\n<html><body>not found</body></html>", consumedData[0]);
    EXPECT_EQ("hello!", consumedData[1]);
}

