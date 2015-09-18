// =====================================================================================
//
//       Filename:  config_reader.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年09月18日 18时04分24秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#include "config_reader.h"
#include "string_util.h"

ConfReader::ConfReader(const std::string &filename)
{
    std::string content = basic_util::read_from_file(filename);
    std::vector<std::string> vec = basic_util::split(content, "\n");
    std::vector<std::string>::size_type i = 0;
    for (; i < vec.size(); ++i)
    {
        std::vector<std::string> kv = basic_util::split(vec[i], "=");
        keypairs_.insert(make_pair(basic_util::trim(kv[0]), basic_util::trim(kv[1])));
    }
}

std::string get(const std::string &key)
{
    std::string value = "";

    return value;
}
