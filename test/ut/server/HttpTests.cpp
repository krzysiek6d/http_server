//
// Created by pawluch on 3/7/19.
//
#include <gtest/gtest.h>
#include <protocols/http/utils/HttpHeaders.h>

TEST(httpheaders_test, should_get_proper_path)
{
    EXPECT_EQ("/", HttpHeaders::getPath("GET / HTTP/1.0\r\n"));
}

TEST(httpheaders_test, code200_should_return_data_with_headers)
{
    EXPECT_EQ("HTTP/1.0 202 OK\r\nServer: led executor\r\nContent-Length: 6\r\n\r\nhello!", HttpHeaders::http202("hello!"));
}

TEST(httpheaders_test, parsePath)
{
    std::map<std::string, std::string> expectedmap;
    expectedmap["key1"] = "value1";
    expectedmap["key2"] = "value2";
    expectedmap["key3"] = "value3";
    auto actual = HttpHeaders::parsePath("/?key1=value1&key2=value2&key3=value3");
    EXPECT_EQ(expectedmap, actual);
}

TEST(httpheaders_test, parsePathCompicated)
{
    std::map<std::string, std::string> expectedmap;
    expectedmap["dn"] = "/MRBTS-1/RAT-1/SMOD_L-1";
    expectedmap["group"] = "1";
    expectedmap["message"] = "2";
    auto actual = HttpHeaders::parsePath("/?dn=/MRBTS-1/RAT-1/SMOD_L-1&group=1&message=2");
    EXPECT_EQ(expectedmap, actual);
}

TEST(httpheaders_test, unescape)
{
    std::string esaped = R"(/?dn=%2FMRBTS-1%2FSMOD_L-1&group=1&message=0)";
    std::string unesaped = R"(/?dn=/MRBTS-1/SMOD_L-1&group=1&message=0)";
    EXPECT_EQ(unesaped, HttpHeaders::unescape(esaped));
}

TEST(httpheaders_test, filepath)
{
    std::string query = R"(/asd/sdasd?dn=%2FMRBTS-1%2FSMOD_L-1&group=1&message=0)";
    std::string path = R"(asd/sdasd)";
    EXPECT_EQ(path, HttpHeaders::getPagePath(query));
}

TEST(httpheaders_test, filepath2)
{
    std::string query = R"(/displ?dn=%2FMRBTS-1%2FBBMOD_L-1&group=0&message=0)";
    std::string path = R"(displ)";
    EXPECT_EQ(path, HttpHeaders::getPagePath(query));
}

//TEST(http_test, mapIsOk)
//{
//    std::map<std::string, std::string> map;
//    map["dn"] = "/MRBTS-1/RAT-1/SMOD_L-1";
//    map["group"] = "1";
//    map["message"] = "2";
//    EXPECT_TRUE(Http().isMapOk(map));
//}
//
//TEST(http_test, mapIsNok)
//{
//    std::map<std::string, std::string> map;
//    map["dnsss"] = "/MRBTS-1/RAT-1/SMOD_L-1";
//    map["group"] = "1";
//    map["message"] = "2";
//    EXPECT_FALSE(Http().isMapOk(map));
//}
//
//TEST(http_test, mapIsNok2)
//{
//    std::map<std::string, std::string> map;
//    map["dn"] = "/MRBTS-1/RAT-1/SMOD_L-1";
//    map["message"] = "2";
//    EXPECT_FALSE(Http().isMapOk(map));
//}
//
