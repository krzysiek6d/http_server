//
// Created by pawluch on 3/7/19.
//
#include <gtest/gtest.h>
#include <server/Http.hpp>

TEST(http_test, should_get_proper_path)
{
    auto http = Http(nullptr, "GET / HTTP/1.0\r\n");
    EXPECT_EQ("/", http.getPath());
}

TEST(http_test, send_should_send_raw_data)
{
    std::vector<std::string> consumedData;
    auto send = [&](const std::string& message)
    {
        consumedData.push_back(message);
    };
    auto http = Http(send, "GET / HTTP/1.0\r\n");
    http.send("hello!");
    EXPECT_EQ("hello!", consumedData[0]);
}

TEST(http_test, code200_should_return_data_with_headers)
{
    std::vector<std::string> consumedData;
    auto send = [&](const std::string& message)
    {
        consumedData.push_back(message);
    };
    auto http = Http(send, "GET / HTTP/1.0\r\n");
    http.http202("hello!");
    EXPECT_EQ("HTTP/1.0 202 OK\r\nServer: led executor\r\nContent-Length: 6\r\n\r\nhello!", http.http202("hello!"));
}

TEST(http_test, parsePath)
{
    auto http = Http(nullptr, "");
    std::map<std::string, std::string> expectedmap;
    expectedmap["key1"] = "value1";
    expectedmap["key2"] = "value2";
    expectedmap["key3"] = "value3";
    auto actual = http.parsePath("/?key1=value1&key2=value2&key3=value3");
    EXPECT_EQ(expectedmap, actual);
}

TEST(http_test, parsePathCompicated)
{
    auto http = Http(nullptr, "");
    std::map<std::string, std::string> expectedmap;
    expectedmap["dn"] = "/MRBTS-1/RAT-1/SMOD_L-1";
    expectedmap["group"] = "1";
    expectedmap["message"] = "2";
    auto actual = http.parsePath("/?dn=/MRBTS-1/RAT-1/SMOD_L-1&group=1&message=2");
    EXPECT_EQ(expectedmap, actual);
}

TEST(http_test, mapIsOk)
{
    auto http = Http(nullptr, "");
    std::map<std::string, std::string> map;
    map["dn"] = "/MRBTS-1/RAT-1/SMOD_L-1";
    map["group"] = "1";
    map["message"] = "2";
    EXPECT_TRUE(http.isMapOk(map));
}

TEST(http_test, mapIsNok)
{
    auto http = Http(nullptr, "");
    std::map<std::string, std::string> map;
    map["dnsss"] = "/MRBTS-1/RAT-1/SMOD_L-1";
    map["group"] = "1";
    map["message"] = "2";
    EXPECT_FALSE(http.isMapOk(map));
}

TEST(http_test, mapIsNok2)
{
    auto http = Http(nullptr, "");
    std::map<std::string, std::string> map;
    map["dn"] = "/MRBTS-1/RAT-1/SMOD_L-1";
    map["message"] = "2";
    EXPECT_FALSE(http.isMapOk(map));
}

TEST(http_test, unescape)
{
    auto http = Http(nullptr, "");
    std::string esaped = R"(/?dn=%2FMRBTS-1%2FSMOD_L-1&group=1&message=0)";
    std::string unesaped = R"(/?dn=/MRBTS-1/SMOD_L-1&group=1&message=0)";
    EXPECT_EQ(unesaped, http.unescape(esaped));
}