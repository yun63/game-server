/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: random.h
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/30 17时57分04秒
 *
 **/


#ifndef  RANDOM_INC
#define  RANDOM_INC

#include "basic_types.h"
#include "noncopyable.h"

namespace base {

class Random : public noncopyable {
public:
    explicit Random(uint32_t seed) : state_(seed) {}

    void Reseed(u_int32_t seed) {
        state_ = seed;
    }

    uint32_t Generate(uint32_t range) {
        state_ = (1103515245U*state_ + 12345U) % kuint32max;
        return state_ % range;
    }

private:
    /* data */
    uint32_t    state_;
};

} // namespace base

#endif   // ----- #ifndef RANDOM_INC  -----
