/*
 * =====================================================================================
 *
 *       Filename:  ranklist.h
 *
 *    Description:  排行榜
 *
 *        Version:  1.0
 *        Created:  2016/10/13 18时08分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  RANKLIST_INC
#define  RANKLIST_INC

#include <algorithm>
#include <functional>

#include <list>
#include <set>
#include <vector>

using namespace std;

/// 模板参数T: 存储的数据类型
/// 模板参数K: 数据的索引
/// 模板参数GetKeyFunc: 仿函数，用于获取索引，索引必须支持比较操作
/// 模板参数CompareFunc: 仿函数，用于比较两个T类型数据
///
template <typename T,
          typename Key,
          typename GetKeyFunc,
          typename CompareFunc>
class RankList {
public:
    RankList(int *aivec, int size);
    RankList(int rank_size, int rank_page_size);
    ~RankList();
    // 检查key是否在榜
    bool check(Key k);
    // 将数据提交到排行榜
    void Commit(const T &item);
    // 查找关键字Key所在的排名 0表示未上榜
    int get_rank(Key k);
    // 获取指定页数据
    bool get_page(int page, std::vector<T> &items);
    const std::list<T> &get_page(int page);
    // 获取区间数据
    bool get_ranke(int begin, int end, std::vector<T> &items);
    // 获取某个排名对应的数据 
    const T &get(int rank);
    // 清空排行榜
    void clear();
    // 现有数据的数目
    int size();
    // 获取指定页面的数量
    int page_size(int page);
    // 总页面数
    int page();
    // 当前页数
    int current_page();
    // 指定页第一个排名
    int FirstPageRank(int page);
    
    bool empty();

private:
    RankList() {}

    // 通过索引查找排名
    int get_rank_by_key(Key k);
    // 插入数据
    void insert(T &item);
    // 删除指定索引的数据
    void erase(Key k);
    // 检查页码合法性
    bool check_page_num(int page);
    // 获取排名所在的页面和序号
    bool get_page_pos_by_rank(int rank, int &page, int &pos);

    static GetKeyFunc get_key_func_;       // 获取关键字索引仿函数
    static CompareFunc compare_data_func_; // 比较数据仿函数

    std::vector<std::list<T> > items_;     // 数据存储容器
    std::set<Key> keys_;                   // 上榜数据的索引
    unsigned int rank_item_num_;           // 需要保存的数量
    unsigned int rank_page_num_;           // 需要保存的页数
    std::vector<int> page_size_vect_;;
};

#endif   // ----- #ifndef RANKLIST_INC  -----
