/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: hash_tables.h
 *
 * @breaf: hash talbe
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/10/24 20时31分51秒
 *
 **/


#ifndef  HASH_TABLES_INC
#define  HASH_TABLES_INC

#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <utility>

#include "hash.h"

namespace base_hash {

template <typename T>
struct hash {
    std::size_t operator()(const T &value) const { return std::hash<T>()(value); }
};

template <typename T1, typename T2>
struct hash<std::pair<T1, T2>> {
    std::size_t operator()(std::pair<T1, T2> value) const {
        return base::HashInts(T1, T2);
    }
};

} // namespace base_hash

namespace base {

template <class Key,
          class T,
          class Hash = base_hash::hash<Key>,
          class Pred = std::equal_to<Key>,
          class Alloc = std::allocator<std::pair<const Key, T>>>
using hash_map = std::unordered_map<Key, T, Hash, Pred, Alloc>;

// Use std::unordered_multimap instead
template <class Key,
          class T,
          class Hash = base_hash::hash<Key>,
          class Pred = std::equal_to<Key>,
          class Alloc = std::allocator<std::pair<const Key, T>>>
using hash_multimap = std::unordered_multimap<Key, T, Hash, Pred, Alloc>;

// Use std::unordered_set instead
template <class Key,
          class Hash = base_hash::hash<Key>,
          class Pred = std::equal_to<Key>,
          class Alloc = std::allocator<Key>>
using hash_set = std::unordered_set<Key, Hash, Pred, Alloc>;

// Use std::unordered_multiset insted
template <class Key,
          class Hash = base_hash::hash<Key>,
          class Pred = std::equal_to<Key>,
          class Alloc = std::allocator<Key>>
using hash_multiset = std::unordered_multiset<Key, Hash, Pred, Alloc>;

} // namespace base

#endif   // ----- #ifndef HASH_TABLES_INC  -----
