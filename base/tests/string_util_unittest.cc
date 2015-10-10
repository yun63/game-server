// =====================================================================================
//
//       Filename:  StringUtil_unittest.cc
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年09月13日 22时01分40秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  yunfei_lei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#include "../utils/string_util.h"

#include <iostream>
#include <algorithm>
#include "gtest/gtest.h"

TEST(StringUtil, join)
{
    std::vector<std::string> tokens;
    tokens.push_back("a");
    tokens.push_back("b");
    EXPECT_EQ(strcmp(basic_util::join(tokens, "+").c_str(), "a+b"), 0);
}

TEST(StringUtil, split)
{
    std::string s = "1-2-3-4-5";
    std::vector<std::string> tokens = basic_util::split(s, "-");
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        EXPECT_EQ(tokens[i], std::to_string(i + 1));
    }
}

TEST(StringUtil, ltrim)
{
    std::string strim = basic_util::ltrim("   hello", " ");
    EXPECT_EQ(strim, "hello");
}

TEST(StringUtil, rtrim)
{
    EXPECT_EQ(basic_util::rtrim("hello    ", " "), "hello");
}

TEST(StringUtil, trim)
{
    std::string s = basic_util::trim("    hello    ", " ");
    EXPECT_EQ(s, "hello");
}

TEST(StringUtil, to_string_int32)
{
    int n32 = 128;
    EXPECT_EQ(basic_util::to_string(n32), "128");
    n32 = 0;
    EXPECT_EQ(basic_util::to_string(n32), "0");
    n32 = -123;
    EXPECT_EQ(basic_util::to_string(n32), "-123");
}

TEST(StringUtil, to_string_int64)
{
    int64_t n64 = 4300000003;
    EXPECT_EQ(basic_util::to_string(n64), "4300000003");
    n64 = -4300000003;
    EXPECT_EQ(basic_util::to_string(n64), "-4300000003");
    n64 = 0;
    EXPECT_EQ(basic_util::to_string(n64), "0");
}

TEST(StringUtil, to_string_double)
{
    double d = 123.456;
    EXPECT_EQ(basic_util::to_string(d), "123.456");
    d = -123.456;
    EXPECT_EQ(basic_util::to_string(d), "-123.456");
    d = 123.456789;
    EXPECT_EQ(basic_util::to_string(d), "123.457");
    d = -123.456789;
    EXPECT_EQ(basic_util::to_string(d), "-123.457");
}

TEST(StringUtil, to_human_readable_string)
{
    uint64_t n = 1024;
    EXPECT_EQ(basic_util::to_human_readable_string(n), "1.000K");

    n *= 1024;
    EXPECT_EQ(basic_util::to_human_readable_string(n), "1.000M");

    n *= 1024;
    EXPECT_EQ(basic_util::to_human_readable_string(n), "1.000G");
}
