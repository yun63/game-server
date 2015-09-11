
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

    return ss;
}

inline string ltrim(const string &str, const string &blank = " ")
{
    string::size_type pos = str.find_last_not_of(blank);
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
    }
}



} // namespace basic_util

#endif
