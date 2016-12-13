/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: atomic_unittest.cc
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/13 19时53分58秒
 *
 **/


#include <gtest/gtest.h>
#include "thread/atomic.h"


TEST(Atomic, all) {
    base::AtomicInt32 n;
    EXPECT_EQ(n.get(), 0);
}

