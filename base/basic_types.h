// =====================================================================================
// 
//    @filename    :  basic_types.h
// 
//    @description :  基本数据类型定义
// 
// -------------------------------------------------------------------------------------
//    @version     :  1.0
//    @created     :  2013年11月12日 16时35分42秒
//    @revision    :  none
//    @compiler    :  g++
// 
//    @author      :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
//    @Company     :  
// 
// =====================================================================================

#ifndef  __BASIC_TYPES__H_
#define  __BASIC_TYPES__H_

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#include "macros.h"

typedef int8_t      int8;
typedef uint8_t     uint8;
typedef int16_t     int16;
typedef uint16_t    uint16;
typedef int32_t     int32;
typedef uint32_t    uint32;

#if defined(__LP64__)
typedef long int64;
typedef unsigned long uint64;
#else
typedef long long int64;
typedef unsigned long long uint64;
#endif

typedef unsigned char byte;

#endif   // ----- #ifndef __BASIC_TYPES__H_ -----
