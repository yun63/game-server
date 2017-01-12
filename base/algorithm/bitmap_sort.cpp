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


void init_bitmap(uint32_t *bm, uint32_t cap) {
    for (uint32_t i = 0; i < cap; i++) {
        bm[i>>kShift] &= ~(0x01 << (i & kMask));
    }
}

void set(uint32_t *bm, uint32_t k) {
    bm[k>>kShift] |= (0x01 << (k & kMask));
}

void clr(uint32_t *bm, uint32_t k) {
    bm[k>>kShift] &= ~(0x01 << (k & kMask));
}

bool test(uint32_t *bm, uint32_t k) {
    return (bm[k>>kShift] & (0x01 << (k & kMask))) != 0;
}

