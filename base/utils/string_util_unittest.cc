// =====================================================================================
//
//       Filename:  string_util_unittest.cc
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

#include "string_util.h"

#include <iostream>
#include "gtest/gtest.h"

TEST(string_util, join)
{
    std::vector<std::string> tokens;
    tokens.push_back("a");
    tokens.push_back("b");
    EXPECT_EQ(strcmp(basic_util::join(tokens, "+").c_str(), "a+b"), 0);
}

TEST(string_util, ltrim)
{
    std::string strim = basic_util::ltrim("   hello", " ");
    EXPECT_EQ(strim, "hello");
}

TEST(string_util, rtrim)
{
    EXPECT_EQ(basic_util::rtrim("hello    ", " "), "hello");
}

TEST(string_util, trim)
{
    std::string s = basic_util::trim("    hello    ", " ");
    EXPECT_EQ(s, "hello");
}
