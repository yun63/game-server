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

#include "algorithm/bitmap_sort.h"
#include "utils/utils.h"

int main(int argc, char *argv[]) {
    base::srand(time(NULL));
    std::vector<std::pair<int, int>> pool{{101, 5000}, {102, 4000}, {103, 500}, {104, 500}};
    int id = base::weighted_random(pool);
    std::cout << id << std::endl;

    int cap = base::rand(10000, 20000);

    init_bitmap(bitmap, cap);

    int i;

    while (std::cin >> i) {
        set(bitmap, i);
        if (i == 1000)
            break;
    }

    for (i = 0; i < N; i++) {
        if (test(bitmap, i)) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
