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
static const int KMask = 0x1f;
static uint32_t bitmap[1 + N/KBitsPerWord];

void init_bitmap(uint32_t *bitmap, uint32_t cap) {
    for (uint32_t i = 0; i < cap; i++) {
        bitmap[i>>KShift] &= ~(0x01 << i&KMask);
    }
}

void set( uint32_t *bitmap, uint32_t k) {
    bitmap[k>>KShift] |= (0x01 << i&KMask);
}

void clr(uint32_t *bitmap, uint32_t k) {
    bitmap[i>>KShift] &= ~(0x01 << i&KMask);
}

bool test(uint32_t *bitmap, uint32_t k) {
    return (bitmap[k>>KShift] & (0x01<<i&KMask) == 1) ? true : false;
}

