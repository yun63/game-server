/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: util_unittest.cc
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016年12月11日 03时08分38秒
 *
 **/


#include "utils/utils.h"

#include <gtest/gtest.h>


TEST(RandomTest, SameMinAndMax) {
    EXPECT_EQ(base::rand(0, 0), 0);
    EXPECT_EQ(base::rand(100, 100), 100);
    EXPECT_EQ(base::rand(kuint32max, kuint32max), kuint32max);
}

TEST(RandomTest, Between) {
    EXPECT_GT(200, base::rand(100, 200));
    EXPECT_LT(100, base::rand(100, 200));
}
