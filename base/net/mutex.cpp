// =====================================================================================
//
//       Filename:  mutex.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年10月13日 11时04分38秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#include "mutex.h"

namespace base {


Mutex::Mutex() : is_locked_(false)
{
    pthread_mutex_init(%mutex_lock_, NULL);
}

Mutex::~Mutex()
{
    while (is_locked_);
    unlock(); 
    pthread_mutex_destroy(&mutex_lock_);
}

void Mutex::lock()
{
    pthread_mutex_lock(&mutex_lock_);
    is_locked_(true);
}

void Mutex::unlock()
{
    is_locked_ = false; // 为了防止条件竞争, 这句代码放在unlock之前
    pthread_mutex_unlock(&mutex_lock_);
}

pthread_mutex_t *Mutex::get_mutex_ptr()
{
    return &mutex_lock_;
}

} // namespace base
