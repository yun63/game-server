// =====================================================================================
//
//       Filename:  noncopyable.h
//
//    Description:  基础类：禁止使用拷贝构造和复制操作函数来构造对象实例
//
//        Version:  1.0
//        Created:  2015年01月14日 18时08分26秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================


#ifndef  NONCOPYABLE_INC
#define  NONCOPYABLE_INC

namespace base {

class noncopyable_
{
    protected:
        noncopyable_() {}
        ~noncopyable_() {}

    private:
        noncopyable_(const noncopyable_ &);
        const noncopyable_ &operator = (const noncopyable_ &);
};

};

typedef base::noncopyable_ noncopyable;

#endif   // ----- #ifndef NONCOPYABLE_INC  ----- 
