/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: bitmap_sort.cpp
 *
 * @breaf: 位图排序
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/19 17时39分34秒
 *
 **/

#include "bitmap_sort.h"

#include <cstdlib>
#include <memory>

static const int KBitsPerWord = 32;
static const int KShift = 5;
static uint32_t bitmap[1 + N/KBitsPerWord];
