/// =====================================================================================
/// 
///    @filename         :  test_main.cc
/// 
///    @description      :  
/// 
///    @version          :  1.0
///    @created          :  2014年09月20日 16时27分36秒
///    @revision         :  none
///    @compiler         :  g++
/// 
///    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
///    @company          :  
/// 
/// =====================================================================================

#include <iostream>
#include "gtest/gtest.h"
#include "base/hello.h"
#include "src/test/test.h"

int main(int argc, char *argv[])
{
    SayHello();
    print();
    std::cout << "############## Google Testing Starting ... #############" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
