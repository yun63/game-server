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


TEST(Atomic, AtomicInt32) {
    base::AtomicInt32 n;
    EXPECT_EQ(n.get(), 0);
    EXPECT_EQ(n.get_and_add(1), 0);
    EXPECT_EQ(n.get(), 1);
    EXPECT_EQ(n.add_and_get(2), 3);
    EXPECT_EQ(n.get(), 3);
    EXPECT_EQ(n.inc_and_get(), 4);
    EXPECT_EQ(n.get(), 4);
    n.inc();
    EXPECT_EQ(n.get(), 5);
    EXPECT_EQ(n.add_and_get(-3), 2);
    EXPECT_EQ(n.get_and_set(100), 2);
    EXPECT_EQ(n.get(), 100);
}

TEST(Atomic, AtomicInt64) {
    base::AtomicInt64 n;
    EXPECT_EQ(n.get(), 0);
    EXPECT_EQ(n.get_and_add(1), 0);
    EXPECT_EQ(n.get(), 1);
    EXPECT_EQ(n.add_and_get(2), 3);
    EXPECT_EQ(n.get(), 3);
    EXPECT_EQ(n.inc_and_get(), 4);
    EXPECT_EQ(n.get(), 4);
    n.inc();
    EXPECT_EQ(n.get(), 5);
    EXPECT_EQ(n.add_and_get(-3), 2);
    EXPECT_EQ(n.get_and_set(100), 2);
    EXPECT_EQ(n.get(), 100);
}

