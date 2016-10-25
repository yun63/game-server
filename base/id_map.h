/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: id_map.h
 *
 * @breaf: 结构体/类隐射成数字id
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/10/25 09时56分37秒
 *
 **/


#ifndef  ID_MAP_INC
#define  ID_MAP_INC

#include <cstddef>
#include <cstdint>
#include <set>

#include "hash_tables.h"
#include "macros.h"

namespace base {

// IDMapOwnPointer -- 指针在析构期间在Remove函数中删除
enum IDMapOwnershipSemantics {
    IDMapExternalPointer = 0,
    IDMapOwnPointer = 1
};

// IDMap对象维护了一系列可以被高效地由id转换成对象对象的指针
template <typename T,
          IDMapOwnershipSemantics OS = IDMapExternalPointer,
          typename K = int32_t>
class IDMap {
public:
    using KeyType = K;

    IDMap() : iteration_depth_(0), next_id_(1), check_on_null_data_(false) {}
    ~IDMap() {
        Releaser<OS, 0>::release_all(&data_);
    }

    void set_check_on_null_data(bool value) {
        check_on_null_data_ = value;
    }

    KeyType Add(T *data) {
        if (data == NULL) {
            return 0;
        }
        KeyType = this_id = next_id_;
    }

private:

    template<IDMapOwnershipSemantics OI, int dummy>
    struct Releaser {
        static inline void release(T *ptr) {}
        static inline void releasea_all(HashTable *table) {}
    };

    template<int dummy>
    struct Releaser<IDMapOwnPointer, dummy> {
        static inline void release(T *ptr) { delete ptr; }
        static inline void release_all(HashTable *table) {
            for (typename HashTable::iterator i = table->begin();
                    i != table->end(); ++i) {
                delete i->second;
            }
            table->clear();
        }
    };

    void Compact() {
        for (const auto &i : removed_ids_) {
            Remove(i);
        }
        removed_ids_.clear();
    }

    DISALLOW_COPY_AND_ASSIGN(IDMap);

    typedef base::hash_map<KeyType, T*> HashTable;

    int iteration_depth_;

    std::set<KeyTpe> removed_ids_;

    KeyType next_id_;

    HashTable data_;

    bool check_on_null_data_;
};


} // namespace base

#endif   // ----- #ifndef ID_MAP_INC  -----
