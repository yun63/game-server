
#ifndef  _STRING_UTIL_H
#define  _STRING_UTIL_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

namespace basic_util {

using std::vector;
using std::string;

inline vector<string> compact(const vector<string> &tokens)
{
    vector<string> compacted_tokens;

    for (size_t i = 0; i < tokens.size(); ++i)
    {
        if (!tokens[i].empty())
        {
            compacted_tokens.push_back(tokens[i]);
        }
    }

    return compacted_tokens;
}

inline vector<string> split(const string &str, const string &delim, const bool trim_whitespace = false)
{
    string::size_type pos = 0;
    string::size_type last_pos = 0;
    vector<string> tokens;
    string::size_type len = 0;

    while (pos != string::npos)
    {
        pos = str.find(delim, last_pos);
        if (pos != string::npos)
        {
            len = pos - last_pos;
            if (!trim_whitespace || len > 0)
            {
                tokens.push_back(str.substr(last_pos, pos - last_pos));
            }
            last_pos = pos + delim.size();
        }
        else
        {
            tokens.push_back(str.substr(last_pos, str.size() - last_pos));
        }
    }

    return tokens;
}

inline string join(const vector<string> &tokens, 
        const string &delim, 
        const bool trim_whitespace = false)
{
    string ss = "";
    for (string::size_type i = 0; i < tokens.size() - 1; ++i)
    {
        string s = tokens[i];
        if (!trim_whitespace || !s.empty())
        {
            ss += (s + delim);
        }
    }

    if (!tokens.empty()) 
    {
        ss += tokens.back();
    }

    return ss;
}

inline string ltrim(const string &str, const string &blank = " ")
{
    string::size_type pos = str.find_first_not_of(blank);
    if (pos == std::string::npos)
    {
        return str;
    }

    return str.substr(pos);
}

inline string rtrim(const string &str, const string &blank = " ")
{
    string::size_type pos = str.find_last_not_of(blank);
    if (pos == std::string::npos)
    {
        return str;
    }

    return str.substr(0, pos + 1);
}

inline string trim(const string &str, const string &blank = " ")
{
    string::size_type pos = str.find_first_not_of(blank);
    if (pos == std::string::npos)
    {
        return str;
    }

    string::size_type pos2 = str.find_last_not_of(blank);
    if (pos2 == std::string::npos)
    {
        return str.substr(pos);
    }

    return str.substr(pos, pos2 - pos + 1);
}

inline string replace_all(string &str, const string &target, const string &replacement)
{
    string::size_type pos = str.find(target);
    while (pos != string::npos)
    {
        str.replace(pos, target.length(), replacement);
        pos = str.find(target);
    }

    return str;
}

// 另一个版本，效率可能不太高
//inline string replace_all(const string &str, const string &target, const string &replacement)
//{
//    return join(split(str, target, false), replacement);
//}

inline string toupper(string &str)
{
    string s(str);
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

inline string tolower(string &str)
{
    string s(str);
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

inline string read_from_file(const string &filepath) {
    std::ifstream in(filepath.c_str());
    string content((std::istreambuf_iterator<char>(in)),
            (std::istreambuf_iterator<char>()));
    in.close();

    return content;
}

inline void write_to_file(const string &content, const string &filepath) {
    std::ofstream out(filepath.c_str());
    out << content;
    out.close();
}

} // namespace basic_util

#endif
