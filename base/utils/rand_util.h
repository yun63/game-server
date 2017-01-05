/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: rand_util.h
 *
 * @breaf: 生成随机数的通用工具
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/29 17时33分21秒
 *
 **/


#ifndef  RAND_UTIL_INC
#define  RAND_UTIL_INC

#include "basic_types.h"

namespace base {

// 生成一个[0, UINT64_MAX]范围的随机数, 线程安全
uint64_t RandUint64();

// 生成一个位于区间(min, max]的随机数，线程安全.
int RandInt(int min, int max);

// 生成一个位于区间[0, range)的随机数，线程安全.
uint64_t RandGenerator(uint64_t range);

// 生成一个位于区间区间[0, 1)double类型的随机数,线程安全
double RandDouble();

} // namespace base

#endif   // ----- #ifndef RAND_UTIL_INC  -----
