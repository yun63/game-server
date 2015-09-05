// =====================================================================================
//
//       Filename:  color_console.h
//
//    Description:  控制台彩色打印文本信息
//
//        Version:  1.0
//        Created:  2015年08月31日 19时28分53秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#ifndef  _COLOR_CONSOLE_H
#define  _COLOR_CONSOLE_H

#include <stdio.h>

#define MAX_STR_LEN 2048

namespace base_util {

#ifdef __linux__
#include <stdarg.h>
#include <string.h>

enum _ForeColor 
{
    FG_BLACK     = 30, // 黑
    FG_RED       = 31, // 红
    FG_GREEN     = 32, // 绿
    FG_YELLOW    = 33, // 黄
    FG_BLUE      = 34, // 蓝
    FG_PURPLE    = 35, // 紫
    FG_DARKGREEN = 36, // 深绿
    FG_WHITE     = 37  // 白
};

typedef _ForeColor FgColor;

enum _BackColor
{
    BG_BLACK     = 40, // 黑
    BG_DARKRED   = 41, // 深红
    BG_GREEN     = 42, // 绿
    BG_YELLOW    = 43, // 黄
    BG_BLUE      = 44, // 蓝
    BG_PURPLE    = 45, // 紫
    BG_DARKGREEN = 46, // 深绿
    BG_WHITE     = 47  // 白
};

typedef _BackColor BgColor;

#endif

#ifdef WIN32
#include <windows.h>

enum _ForeColor
{
    FG_BLACK     = 0, // 黑
    FG_RED       = FOREGROUND_INTENSITY | FOREGROUND_RED, // 红
    FG_GREEN     = FOREGROUND_INTENSITY | FOREGROUND_GREEN, // 绿
    FG_YELLOW    = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN, // 黄
    FG_BLUE      = FOREGROUND_INTENSITY | FOREGROUND_BLUE,// 蓝
    FG_PURPLE    = FOREGROUND_RED | FOREGROUND_BLUE, // 紫
    FG_DARKGREEN = FOREGROUND_GREEN, // 深绿
    FG_WHITE     = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE, // 白
};

typedef _ForeColor FgColor;

enum _BackColor
{
     BG_BLACK     = 0, //黑
     BG_DARKRED   = BACKGROUND_RED, //深红
     BG_GREEN     = BACKGROUND_INTENSITY | BACKGROUND_GREEN, //绿
     BG_YELLOW    = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN, //黄
     BG_BLUE      = BACKGROUND_INTENSITY | BACKGROUND_BLUE, //蓝
     BG_PURPLE    = BACKGROUND_RED | BACKGROUND_BLUE, //紫
     BG_DARKGREEN = BACKGROUND_GREEN, //深绿
     BG_WHITE     = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE //白
};

typedef _BackColor BgColor;

#endif

int print(FgColor fg, const char *format_str, ...)
{
    int len = 0;
#ifdef __linux__
    printf("\e[%dm", fg);
    va_list plist;
    va_start(plist, format_str);
    len = vprintf(format_str, plist);
    va_end(plist);
    printf("\e[0m"); // 关闭所有属性
#endif

#ifdef WIN32
    CONSOLE_SCREEN_BUFFER_INFO oldInfo = {0};
    HANDLE hstd = ::GetStdHandle(STD_OUTPUT_HANDLE);
    if (hstd != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hStd, &oldInfo))
    {
        SetConsoleTextAttribute(hstd, fg);

        va_list plist;
        va_start(plist, format_str);
        len = vsnprintf(text, sizeof(text), format_str, plist);
        va_end(plist);

        SetConsoleTextAttribute(hstd, oldInfo.wAttributes);
    }
#endif

    return len;
}

int print(FgColor fg, BgColor bg, const char *format_str, ...)
{
    int len = 0;
#ifdef __linux__
    static char text[MAX_STR_LEN] = {0};
    memset(text, 0, sizeof(text));

    va_list plist;
    va_start(plist, format_str);
    len = vsnprintf(text, sizeof(text), format_str, plist);
    va_end(plist);

    bool last_is_lf = (text[len - 1] == '\n');
    char *p = strtok(text, "\n");
    while (p != NULL)
    {
        printf("\e[%d;%dm%s\e[0m", fg, bg, p);
        p = strtok(NULL, "\n");
        if (p != NULL || last_is_lf)
        {
            printf("\n");
        }
    }
#endif

#ifdef WIN32
    CONSOLE_SCREEN_BUFFER_INFO oldInfo = {0};
    HANDLE hstd = ::GetStdHandle(STD_OUTPUT_HANDLE);
    if (hstd != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hstd, &oldInfo))
    {
        SetConsoleTextAttribute(hstd, fg | bg);

        va_list plist;
        va_start(plist, format_str);
        len = vprintf(format_str, plist);
        va_end(plist);

        SetConsoleTextAttribute(hstd, oldInfo.wAttributes);
    }
#endif

    return len;
}

} // namespace base_util

typedef base_util::FgColor FgColor;
typedef base_util::BgColor BgColor;

#endif
