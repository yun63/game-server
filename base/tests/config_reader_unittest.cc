// =====================================================================================
//
//       Filename:  config_reader_unittest.cc
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年09月21日 12时20分23秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#include "../utils/config_reader.h"
#include <gtest/gtest.h>

TEST(ConfReaderTest, get)
{
    ConfReader cfg("./tests/my.conf");
    std::string user = cfg.get("username");
    std::string pass = cfg.get("password");
    EXPECT_EQ(user, "root");
    EXPECT_EQ(pass, "root3gx");
}
