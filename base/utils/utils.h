/***************************************************************************
 *
 * Copyright © 2016 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: utils.h
 *
 * @breaf: 一组通用工具
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2016/12/29 16时05分45秒
 *
 **/


#ifndef  UTILS_INC
#define  UTILS_INC

#include <vector>
#include <string>
#include <cstdlib>
#include <utility>

#include "random.h"


namespace base {


/**
 * Return a float random inside the internal [0, mod]
 */
inline float frand(float mod) {
    double r = static_cast<double>(rand());
    r /= static_cast<double>(RAND_MAX);
    return static_cast<float>(r * mod);
}

/**
 * Return a random between [0, 10000)
 *
 */
uint32_t rand() {
    base::Random rand(10000);
    return rand.Generate();
}

/**
 * @brief Return a random between [0, limit)
 *
 * @param limit
 *
 * @return  random number
 */
uint32_t rand(uint32_t limit) {
    if (limit == 0) {
        return 0;
    }

    base::Random rand(limit);
    return rand.Generate();
}


/**
 * @brief Return a number between[a, b) if a < b or between [b, a) if a > b
 *
 * @param a
 * @param b
 *
 * @return random number between a and b
 */
uint32_t rand(uint32_t a, uint32_t b) {
    if (a == b) {
        return a;
    }

    base::Random rand(::abs(a - b));
    return std::min(a, b) + rand.Generate();
}

/**
 * @brief Set random seed
 *
 * @param seed
 */
void srand(uint32_t seed) {
    base::Random rand;
    rand.set_seed(seed);
}

void set_random_limit(uint32_t limit) {
    base::Random rand;
    rand.set_upper_limit(limit + 1);
}

int weighted_random(std::vector<std::pair<int, int>> pool) {
    int sum = 0;
    for (size_t i = 0; i < pool.size(); i++) {
        sum += pool[i].second;
    }

    int rbase = base::rand(sum);
    int cur = 0;

    for (auto it = pool.begin(); it != pool.end(); it++) {
        if (rbase > cur && rbase <= cur + it->second) {
            return it->first;
        }
        cur += it->second;
    }

    return 0;
}

/**
 * Return the square of a number
 */
template<typename T>
inline T sqr(const T &v)
{
    return v * v;
}

/*
 * min or max extended functions
 */
template<typename T>
inline T min_of(const T &a, const T &b, const T &c)
{
    return std::min(std::min(a, b), c);
}

template<typename T>
inline T min_of(const T &a, const T &b, const T &c, const T &d)
{
    return std::min(min_of(a, b, c), d);
}

template<typename T>
inline T max_of(const T &a, const T &b, const T &c)
{
    return std::max(std::max(a, b), c);
}

template<typename T>
inline T max_of(const T &a, const T &b, const T &c, const T &d)
{
    return std::max(max_of(a, b, c), d);
}
/*
 * Return the value maximized to the next power of 2 of v.
 * eg:
 *  raise_to_next_powerof2(8) = 8
 *  raise_to_next_powerof2(5) = 8
 *  raise_to_next_powerof2(3) = 4
 */
uint32 raise_to_next_powerof2(uint32 v);

/*
 * Return true if the value is a power of 2.
 */
bool is_powerof2(uint32 v);

/*
 * Convert a string in lower case
 * @param str: a string to transform to lower case
 */
std::string tolower(const std::string &str);
void tolower(char *str);

/*
 * Convert a string in upper case
 * @param str: a string to transform to upper case
 */
std::string toupper(const std::string &str);
void toupper(char *str);

template<typename T> 
T trim(const T &str) {
    typename T::size_type start = 0;
    const typename T::size_type size = str.size();
    while (start < size && str[start] <= 32) start++;
    typename T::size_type end = size;
    while (end > start && str[end - 1] <= 32) end--;

    return str.substr(start, end - start);
}

/*
 * Remove spaces at the end of the string
 */
template<typename T>
T trim_right_spaces(const T &str) {
    typename T::size_type end = str.size();
    while (end > 0 && str[end - 1] == ' ') end--;
    return str.substr(0, end);
}

/*
 * Remove spaces at the beginning of the string
 */
template<typename T>
T trim_left_spaces(const T &str) {
    typename T::size_type start = 0;
    typename T::size_type end = str.size();
    while (str[start] == ' ') start++;
    return str.substr(start, end - 1);
}

inline std::string &strlwr(std::string &str) {
    str = tolower(str);
    return str;
}


inline std::string strlwr(const std::string &str) {
    return tolower(str);
}

inline char *strlwr(char *str) {
    tolower(str);
    return str;
}

inline std::string &strupr(std::string &str) {
    str = toupper(str);
    return str;
}

inline std::string strupr(const std::string &str) {
    return toupper(str);
}

inline char *strupr(char *str) {
    toupper(str);
    return str;
}

/*
 * Convert a human readable into a bytes,
 * eg:
 * "102kb" -> 105123
 */
uint32 humanreadable_to_bytes(const std::string &str);

/*
 * Convert a number in bytes into a string that is easily readable by an human
 * eg:
 * 105123 -> "102kb"
 */
std::string bytes_to_humanreadable(const std::string &types);
std::string bytes_to_humanreadable(uint64 bytes);

std::string seconds_to_humanreadable(uint32 time);

} // namespace base


#endif   // ----- #ifndef UTILS_INC  -----
