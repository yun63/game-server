// =====================================================================================
//
//       Filename:  mutex.h
//
//    Description:  POSIX锁
//
//        Version:  1.0
//        Created:  2015年10月13日 10时57分01秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#ifndef  _MUTEX_H
#define  _MUTEX_H

#include <unistd.h>
#include <pthread.h>

namespace base {


class Mutex
{
    public:
        Mutex();
        ~Mutex();
        void lock();
        void unlock();
        pthread_mutex_t *get_mutex_ptr();

    private:
        volatile bool is_locked_;
        pthread_mutex_t mutex_lock_;
};

};

#endif
