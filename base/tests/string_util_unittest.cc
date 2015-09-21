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
