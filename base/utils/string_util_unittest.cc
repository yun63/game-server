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
    tokens.push_back("hello");
    std::cout << basic_util::join(tokens, "world");
    EXPECT_EQ(strcmp(basic_util::join(tokens, "world").c_str(), "helloworld"), 0);
}

TEST(string_util, ltrim)
{
    std::string strim = basic_util::ltrim("   hello", " ");
    std::cout << strim << std::endl;
    EXPECT_EQ(strim, "hello");
}

TEST(string_util, rtrim)
{
    EXPECT_EQ(basic_util::rtrim("hello    ", " "), "hello");
}

TEST(string_util, trim)
{
    std::string s = basic_util::trim("    hello    ", " ");
    std::cout << s << std::endl;
    EXPECT_EQ(s, "hello");
}
