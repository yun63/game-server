/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: hash_unittest.cc
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016-10-21 21:19
 *
 **/

#include "../hash.h"

#include <string>
#include <vector>

#include <gtest/gtest.h>

namespace base {

TEST(HashTest, String) {
    std::string str;
    str = "";
    EXPECT_EQ(0u, Hash(str));

    str = "hello world";
    EXPECT_EQ(2794219650u, Hash(str));

    str = "helmo world";
    EXPECT_EQ(1006697176u, Hash(str));

    str = "hello  world";
    str[5] = '\0';
    EXPECT_EQ(2319902537u, Hash(str));

    str = "hello  worle";
    str[5] = '\0';
    EXPECT_EQ(553904462u, Hash(str));

    std::vector<char> long_string_buffer;
    for (int i = 0; i < 4096; i++) {
        long_string_buffer.push_back((i % 256) - 128);
    }
    str.assign(&long_string_buffer.front(), long_string_buffer.size());
    EXPECT_EQ(2797962408u, Hash(str));

    str = "hello w\xab";
    EXPECT_EQ(615571198u, Hash(str));
    str = "hello wo\xab";
    EXPECT_EQ(623474296u, Hash(str));
    str = "hello wor\xab";
    EXPECT_EQ(4278562408u, Hash(str));
    str = "hello worl\xab";
    EXPECT_EQ(3224633008u, Hash(str));
}

TEST(HashTest, CString) {
    const char *str;
    str = "";
    EXPECT_EQ(0u, Hash(str, strlen(str)));

    str = "hello world";
    EXPECT_EQ(2794219650u, Hash(str, strlen(str)));

    str = "hello world; don't read this part";
    EXPECT_EQ(2794219650u, Hash(str, strlen("hello world")));
}

}
