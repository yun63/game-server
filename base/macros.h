/// =====================================================================================
/// 
///    @filename         :  macros.h
/// 
///    @description      :  
/// 
/// -------------------------------------------------------------------------------------
///    @version          :  1.0
///    @created          :  2014年07月14日 20时59分47秒
///    @revision         :  none
///    @compiler         :  g++
/// 
///    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
///    @Company          :  
/// 
/// =====================================================================================

#ifndef  __MACROS__H_
#define  __MACROS__H_

#include <stddef.h>
#include <string.h>

#define     MAX_LINE        4096
#define     BUFF_SIZE       8192

#define     I64FMTD         "%llu"

/* Default file access permissions for new files 
 */
#define FILE_MODE	(S_IRUSR | S_IWUSE | S_IRGRP | S_IROTH)

/* Default permissions for new directories
 */
#define DIR_MODE	(FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

//#include "compiler_specific.h"

// Put this in the private:declarations for a class to be uncopyable.
#define DISALLOW_COPY(TypeName) \
    TypeName(const TypeName &)

// Put this in the private:declarations for a class to be unassignable.
#define DISALLOW_ASSIGN(TypeName) \
    void operator=(const TypeName &)

// A macro to disallow the copy constructor and operator = functions
// This should be used in the private:declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName &);            \
    void operator = (const TypeName &)

template <typename T, size_t N>
char (&ArraySizeHelper(const T (&array)[N]))[N];

#define ARRAY_SIZE(array)   (sizeof(ArraySizeHelper(array)))

template <typename To, typename From>
inline To implicit_cast(From const &f)
{
    return f;
}

#undef ASSERT_STR

#if __cplusplus >= 201103L
// c++11
#define ASSERT_STR(expr, msg)   static_assert(expr, #msg)

#else

#define ASSERT_STR(expr, msg) 

#endif



#endif   // ----- #ifndef __MACROS__H_ -----
