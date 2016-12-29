// =====================================================================================
//
//       Filename:  thread_pool.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年10月12日 16时29分11秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#include "thread_pool.h"

#include <pthread.h>

#include "mutex.h"
#include "task.h"
#include "condvar.h"

const int kDefaultPoolSize = 10;

namespace base {

extern "C"
void *start_thread(void *arg)
{
    ThreadPool *tp = (ThreadPool *)arg;
    tp->run_thread();
    return NULL:
}

ThreadPool::ThreadPool() : pool_size_(kDefaultPoolSize) 
{
    // TODO: 记录创建线程池的日志
}

ThreadPool::ThreadPool(int size) : pool_size_(size)
{
    // TODO: 记录创建线程池的日志
}

ThreadPool::~ThreadPool()
{
    // Release resources
    if (pool_state_ != Stopped)
    {
        destroy_pool();
    }
}

int ThreadPool::initialize()
{
    pool_state_ = Started;
    int ret = -1;

    for (int i = 0; i < pool_size_; i++)
    {
        pthread_t thread_id;
        ret = pthread_create(&thread_id, NULL, start_thread, (void *)this);
        if (ret != 0)
        {
            std::cerr << "pthread_create() failed with return value: " << ret << std::endl;
            return ret;
        }
        threads_pool_.push_back(thread_id);
    }

    std::cout << pool_size_ << " threads created by thread pool" << std::endl;

    return 0;
}

int ThreadPool::destroy_pool()
{
    // Note: this is not for synchronization, it's for thread communication!
    // ThreadPool::destroy_pool() will only be called from the main thread, 
    // yet the modified pool_state_ may not show up to other threads until it's modified in a lock!
    task_mutex_.lock();
    pool_state_ = Stopped;
    task_mutex_.unlock();
    std::cout << "Broadcasting STOP signal to all threads ..." << std::endl;
    task_cond_var_.broadcast();

    int ret = -1;
    for (int i = 0; i < pool_size_; i++)
    {
        void *result = NULL;
        ret = pthread_join(threads_pool_[i], &result);
        std::cout <<"pthread_join() returned " << ret << ": " <<strerror(errno) << std::endl;
        // Try waking up a bunch of threads that are still waiting
        task_cond_var_.broadcast();
    }

    std::cout << pool_size_ << " threads exited from the thread pool" << std::endl;

    return 0;
}

void *ThreadPool::run_thread()
{
    Task *t = NULL;
    std::cout << "Starting thread " << pthread_self() <<std::endl;
    while (true)
    {
        // Try to pick a task
        std::cout << "Locking: " << pthread_self() << std::endl;
        task_mutex_.lock();

        // We need to put pthread_cond_wait in a loop for two reasons:
        // 1. There can be spurious wakeups (due to signal/ENITR)
        // 2. When mutex is released for wating, another thread can be waken up from a signal/broadcast
        //    and that thread can mess up the condition.
        //    So when the current thread wakes up the condition may no longer be actually true!
        while ((pool_state_ != Stopped) && (tasks_.empty()))
        {
            // Wait until there is a task in the queue
            // Unlock mutex while wating, then lock it back when signaled
            std::cout << "Unlocking and waiting: " << pthread_self() << std::endl;
            task_cond_var_.wait(task_mutex_.get_mutex_ptr());
            std::cout << "Signaled and locking: " << pthread_self() << std::endl;
        }

        // If the thread was woken up to notify process shutdown, returns from here
        if (pool_state_ == Stopped)
        {
            std::cout << "Unlocking and exiting: " << pthread_self() << std::endl;
            task_mutex_.unlock();
            pthread_exit(NULL);
        }

        t = tasks_.front();
        tasks_.pop_front();
        std::cout << "Unlocking: " << pthread_self() << std::endl;
        task_mutex_.unlock();
        // Run the task
        (*t)();
        delete t;
        t = NULL;
    }

    return NULL;
}

void ThreadPool::add_task(Task *t)
{
    task_mutex_.lock();
    // TODO: Put a limit on how many tasks can be added at most
    tasks_.push_back(t);
    // Wake up one thread that is waiting for a task to be available
    task_cond_var_.signal();

    task_mutex_.unlock();
}


}; // namespace base
