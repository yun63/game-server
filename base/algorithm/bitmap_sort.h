/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: bitmap_sort.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/19 17时34分52秒
 *
 **/


#ifndef  BITMAP_SORT_INC
#define  BITMAP_SORT_INC

#include <stdint.h>

static const int kBitsPerWord = 32;
static const int kShift = 5;
static const int kMask = 0x1f;
static const int N = 10000000;
static uint32_t bitmap[1 + N/kBitsPerWord];

void init_bitmap(uint32_t *bm, uint32_t cap);
void set(uint32_t *bm, uint32_t k);
void clr(uint32_t *bm, uint32_t k);
bool test(uint32_t *bm, uint32_t k);

#endif   // ----- #ifndef BITMAP_SORT_INC  -----
