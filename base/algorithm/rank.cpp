/*
 * =====================================================================================
 *
 *       Filename:  rank.cpp
 *
 *    Description:  找出vector中元素的排序次序
 *
 *        Version:  1.0
 *        Created:  2016/10/13 16时32分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>


template <typename T,
          typename CompareFunc>
void rank(const std::vector<T> &vect, int *rank, CompareFunc compf) {
    int len = vect.size();
    std::vector<int> index(len, 0);
    for (int i = 0; i < len; i++) {
        index[i] = i;
    }

    sort(index.begin(), index.end(),
        [&](const T &a, const T &b) {
            return compf(vect[a], vect[b]);
        }
    );

    for (int i = 0; i < len; i++) {
        std::cout << vect[i] << "\t" << index[i] << std::endl;
    }

    int current = 1, skip = 1;
    *(rank + index[0]) = current;
    for (int i = 1; i < len; i++) {
        if (vect[index[i]] == vect[index[i-1]]) {
            ++skip;
        } else {
            current += skip;
            skip = 1;
        }
        *(rank + index[i]) = current;
    }
}

