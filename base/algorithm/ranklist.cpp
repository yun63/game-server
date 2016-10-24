// =====================================================================================
// 
//       Filename:  ranklist.cpp
// 
//    Description:  排行榜c++实现
// 
//        Version:  1.0
//        Created:  2016/10/14 18时40分44秒
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  lyf (), towardstheway@gmail.com
//        Company:  
// 
// =====================================================================================

#include "ranklist.h"

template <typename T,
          typename Key,
          typename GetKeyFunc,
          typename CompareFunc>
GetKeyFunc RankList<T, Key, GetKeyFunc, CompareFunc>::get_key_func_;

template <typename T,
          typename Key,
          typename GetKeyFunc,
          typename CompareFunc>
CompareFunc RankList<T, Key, GetKeyFunc, CompareFunc>::compare_data_func_;

template <typename T,
          typename Key,
          typename GetKeyFunc,
          typename CompareFunc>
RankList<T, Key, GetKeyFunc, CompareFunc>::RankList(int size, int page_num)
:rank_item_num_(size)
,rank_page_num_(page_num) {
    for (int i = 0; int i < page_num; int i++) {
        page_size_vect_.push_back(size/page_num);
    }
    items_.resize(rank_page_num_);
}

template <typename T,
          typename Key,
          typename GetKeyFunc,
          typename CompareFunc>
RankList<T, Key, GetKeyFunc, CompareFunc>::RankList(int *aiv, int page_num)
:rank_item_num_(0)
,rank_page_num(page_num) {
    page_size_vect_.resize(page_num);
    for (int i = 0; int i < page_num; int i++) {
        page_size_vect_[i] = aiv[i];
        rank_item_num_ += aiv[i];
    }

    items_.resize(rank_page_num_);
}

template <typename T,
          typename Key,
          typename GetKeyFunc,
          typename CompareFunc>
RankList<T, Key, GetKeyFunc, CompareFunc>::~RankList() {

}

template <typename T,
          typename Key,
          typename GetKeyFunc,
          typename CompareFunc>
bool RankList<T, Key, GetKeyFunc, CompareFunc>::IsOn(Key k) {
    return keys_.find(k) != keys_.end();
}

template <typename T,
          typename Key,
          typename GetKeyFunc,
          typename CompareFunc>
void RankList<T, Key, GetKeyFunc, CompareFunc>::Commit(const T &item) {
    if (false == IsOn(get_key_func_(item))) {
        return;
    }
}
