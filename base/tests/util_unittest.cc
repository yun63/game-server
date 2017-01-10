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

#include <ctime>
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

TEST(RandomTest, WeightRandom) {
    std::vector<std::pair<int, int>> pool;
    typedef std::pair<int, int> _Pair;
    _Pair p1 = std::make_pair(101, 2000);
    _Pair p2 = std::make_pair(102, 500);
    _Pair p3 = std::make_pair(103, 5000);
    _Pair p4 = std::make_pair(104, 2500);
    pool.push_back(p1);
    pool.push_back(p2);
    pool.push_back(p3);
    pool.push_back(p4);
    int id = base::weighted_random(pool);
    std::cout << id << std::endl;
    EXPECT_EQ(1, 1);
}
