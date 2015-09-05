/// =====================================================================================
/// 
///    @filename         :  float_util.h
/// 
///    @description      :  浮点数通用辅助函数
/// 
///    @version          :  1.0
///    @created          :  2014年10月22日 20时40分23秒
///    @revision         :  none
///    @compiler         :  g++
/// 
///    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
///    @Company          :  
/// 
/// =====================================================================================

#ifndef  __FLOAT_UTIL__H_
#define  __FLOAT_UTIL__H_

#include <float.h>
#include <cmath>

namespace base_util {

template <typename Float>
inline bool IsFinite(const Float &number)
{
#if defined(__linux__)
    return std::isfinite(number) != 0;
#elif defined(_WIN32)
    return _finite(number) != 0;
#endif
}

template <typename Float>
inline bool IsNaN(const Float &number)
{
#if defined(__linux__)
    return std::isnan(number) != 0;
#elif defined(_WIN32)
    return _isnan(number) != 0;
#endif
}

} // namespace base_util

#endif   // ----- #ifndef __FLOAT_UTIL__H_ -----

