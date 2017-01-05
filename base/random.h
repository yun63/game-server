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
    explicit Random(uint32_t upper = kint32max) {
        upper_limit_ = upper;
    }

    uint32_t Generate() const;

    void set_seed(uint32_t seed) {
        seed_ = seed;
    }

private:
    void set_upper_limit(uint32_t)

private:
    /* data */
    uint32_t    state_;
};

} // namespace base

#endif   // ----- #ifndef RANDOM_INC  -----
