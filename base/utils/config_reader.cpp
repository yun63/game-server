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

#include <utility>
#include "string_util.h"

ConfReader::ConfReader(const std::string &filename)
{
    std::string content = basic_util::read_from_file(filename);
    std::vector<std::string> vec = basic_util::split(content, "\n");
    std::vector<std::string>::size_type i = 0;
    for (; i < vec.size(); ++i)
    {
        std::vector<std::string> kv = basic_util::split(vec[i], "=");
        if (kv.size() == 2)
        {// only when both of key and value exist, pair is valid
            keypairs_.insert(make_pair(basic_util::trim(kv[0]), basic_util::trim(kv[1])));
        }
    }
}

std::string ConfReader::get(const std::string &key)
{
    std::map<std::string, std::string>::const_iterator it = keypairs_.find(key);
    if (it != keypairs_.end()) 
    {
        return it->second;
    }

    return "";
}
