// =====================================================================================
//
//       Filename:  config_unittest.cc
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年09月18日 10时37分34秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#include "../utils/config.h"
#include "gtest/gtest.h"

using namespace basic_util;

TEST(Config, IsFileExist)
{
    Config cfg("test.ini");
    cfg.save();
    EXPECT_EQ(cfg.IsFileExist(), true);
}
