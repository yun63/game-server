// =====================================================================================
//
//       Filename:  config_reader.h
//
//    Description:  一个简单的配置文件提取工具
//
//        Version:  1.0
//        Created:  2015年09月18日 17时53分25秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================


#ifndef  _CONFIG_READER_H
#define  _CONFIG_READER_H

#include <string>
#include <map>

class ConfReader
{
    public:
        ConfReader(const std::string &filename);
        std::string get(const std::string &key);

    private:
        std::map<std::string, std::string> keypairs_;
};

#endif
