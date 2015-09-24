/// =====================================================================================
/// 
///    @filename         :  bits.h
/// 
///    @description      :  This file defines some bit utilities.
/// 
/// -------------------------------------------------------------------------------------
///    @version          :  1.0
///    @created          :  2014年07月21日 11时38分24秒
///    @revision         :  none
///    @compiler         :  g++
/// 
///    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
///    @Company          :  
/// 
/// =====================================================================================

#ifndef  __BITS__H_
#define  __BITS__H_

#include "basic_types.h"

namespace base {
namespace bits {

// Returns the integer i such as 2^i <= n < 2 ^ (i+1)
inline int Log2Floor(uint32 n)
{
    if (n == 0) return -1;
    int log = 0;
    uint32 value = n;
    for (int i = 4; i >= 0; --i)
    {
        int shift = (1 << i);
        uint32 x = value >> shift;
        if (x != 0)
        {
            value = x;
            log += shift;
        }
    }
    return log;
}

// Returns the integer i such as 2 ^(i-1) < n <= 2^i
inline int Log2Ceiling(uint32 n)
{
    if (n == 0) return -1;
    return 1 + Log2Floor(n - 1);
}


} // namespace bits
} // namespace base

#endif   // ----- #ifndef __BITS__H_ -----
