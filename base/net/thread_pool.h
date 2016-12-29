// =====================================================================================
//
//       Filename:  thread_pool.h
//
//    Description:  基于POSIX thread的线程池C++实现
//
//        Version:  1.0
//        Created:  2015年10月12日 16时21分11秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#ifndef  _THREAD_POOL_H
#define  _THREAD_POOL_H

#include <vector>
#include <deque>
#include <pthread.h>

namespace base {


class Mutex;
class Task;

class ThreadPool
{
    public:
        ThreadPool();
        ThreadPool(int pool_size);
        ~ThreadPool();
        int initialize();
        int destroy_pool();
        void *run_thread();
        void add_task(Task *task);

    private:
        enum {
            Started = 0, 
            Stopped = 1
        };
        int pool_size_;
        Mutex task_mutex_;
        CondVar task_cond_var_;
        std::vector<pthread_t> threads_pool_; // 线程池，存储线程
        std::deque<Task *> tasks_;
        volatile int pool_state_;
};

} // namespace base

#endif
