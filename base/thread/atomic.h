/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: atomic.h
 *
 * @breaf: 原子操作
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/13 19时14分24秒
 *
 **/


#include <stdint.h>

#include "noncopyable.h"

namespace base {

template<typename T>
class AtomicIntegerT : public noncopyable {
public:
    AtomicIntegerT() : value_(0) {}

    T get() const {
        return __sync_val_compare_and_swap(const_cast<volatile T*>(&value_), 0, 0);
    }

    T get_and_add(T x) {
        return __sync_fetch_and_add(&value_, x);
    }

    T add_and_get(T x) {
        return __sync_add_and_fetch(&value_, x);
    }

    T inc_and_get() {
        return add_and_get(1);
    }

    void add(T x) {
        get_and_add(x);
    }

    void inc() {
        inc_and_get();
    }

    void dec() {
        get_and_add(-1);
    }

    T get_and_set(T nv) {
        return __sync_lock_test_and_set(&value_, nv);
    }

private:
    volatile T value_; // volatile 每次取值都会从变量value_中读取，杜绝编译器优化
};

typedef AtomicIntegerT<int32_t> AtomicInt32;
typedef AtomicIntegerT<int64_t> AtomicInt64;

} // namespace base
