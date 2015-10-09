// =====================================================================================
//
//       Filename:  bits_unittest.cc
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年10月09日 21时02分20秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  yunfei_lei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#include "../bits.h"

#include <gtest/gtest.h>


using namespace base::bits;

TEST(bits, Log2Floor)
{
    EXPECT_EQ(Log2Floor(1021), 9);
    EXPECT_EQ(Log2Floor(1024), 10);
    EXPECT_EQ(Log2Floor(1), 0);
    EXPECT_EQ(Log2Floor(0), -1);
}

TEST(bits, Log2Ceiling)
{
    EXPECT_EQ(Log2Ceiling(1021), 10);
    EXPECT_EQ(Log2Ceiling(1024), 10);
    EXPECT_EQ(Log2Ceiling(1), 0);
    EXPECT_EQ(Log2Ceiling(0), -1);
}
