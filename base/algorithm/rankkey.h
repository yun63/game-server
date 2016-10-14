// =====================================================================================
// 
//       Filename:  rankkey.h
// 
//    Description:  排序数据关键字
// 
//        Version:  1.0
//        Created:  2016/10/13 18时54分04秒
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  lyf (), towardstheway@gmail.com
//        Company:  
// 
// =====================================================================================


#ifndef  RANKKEY_INC
#define  RANKKEY_INC

#include <string>

struct RankData {
    int id;
    int time;
    int values;
};

struct RankPlayerLevel {
    int id;
    std::string name;
    int time;
    int power;
}

class RankDataKey {
public:
    int operator()(RankData *aidata) const {
        return aidata->id;
    }
};

class RankPlayerLevelKey {
public:
    int operator()(RankPlayerLevel *aidata) const {
        return aidata->power;
    }
};

#endif   // ----- #ifndef RANKKEY_INC  -----
