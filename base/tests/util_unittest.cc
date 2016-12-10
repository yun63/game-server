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
}
