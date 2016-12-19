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

void init_bitmap(uint32_t *bitmap, uint32_t cap);
void set(uint32_t *bitmap, uint32_t k);
void clr(uint32_t *bitmap,, uint32_t k);
void test(uint32_t *bitmap, uint32_t k);

#endif   // ----- #ifndef BITMAP_SORT_INC  -----
