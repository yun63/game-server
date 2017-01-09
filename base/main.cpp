/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: main.cpp
 *
 * @breaf: 
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/01/09 22时17分31秒
 *
 **/

#include <iostream>
#include <ctime>
#include <unistd.h>

#include "utils/utils.h"

int main(int argc, char *argv[]) {
    base::srand(time(NULL));
    while (true) {
        std::cout << base::rand(10000) << std::endl;
        sleep(1);
    }
    return 0;
}
