#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

typedef          char   i8;
typedef          short  i16;
typedef          int    i32;
typedef          long   i64;
typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;
typedef unsigned long   u64;

namespace de
{
    // set text color in console
    inline std::string cmd_txt_col(u8 r, u8 g, u8 b);
    // reset text color in console
    inline std::string cmd_txt_col_reset();
    // set background color in console
    inline std::string cmd_back_col(u8 r, u8 g, u8 b);


    // проверяет что строка являеться числом
    bool sisd(std::string str);
    // проверяет что строка являеться шеснацетеричным числом
    bool sisd_hex(std::string str);
    // проверяет что строка являеться двоичным числом
    bool sisd_bin(std::string str);

    // возвращает строку без символов cing
    std::string signore(std::string str, char cign);

    // срез строки от start до end, не включая end
    std::string slise(std::string str, int start, int end);

    // срез вектора от start до end, не включая end
    template<typename T>
    std::vector<T> slise(std::vector<T> vec, int start, int end);

    // возвращает строку без пробелов в начале и конце
    std::string trim(std::string str);

    // разделяет строку по символу splitter
    std::vector<std::string> split(std::string str, char splitter);

    // функция обратная split
    // принимает вектор, а возвращает одну строку
    std::string merge(std::vector<std::string> strs, char splitter);

    // возвращает строку до первого втретившегося символа C
    std::string toc(std::string str, char C);

    // возвращает строку после первого втретившегося символа C
    std::string aftc(std::string str, char C);

    // добовляет все элементы new_vec в конец вектора vec
    template<typename T>
    void push_vec(std::vector<T> *vec, std::vector<T> new_vec);
    
    // разделяет строку на две: до splitter, и после, не включая splitter
    std::pair<std::string, std::string> twsplit(std::string str, char splitter);
}

inline std::string de::cmd_txt_col(u8 r, u8 g, u8 b)
{
    return "\033[38;2;"
            + std::to_string(r) + ";"
            + std::to_string(g) + ";"
            + std::to_string(b) + "m";
}
inline std::string cmd_txt_col_reset()
{
    return "\033[00m";
}
inline std::string de::cmd_back_col(u8 r, u8 g, u8 b)
{
    return "\033[48;2;"
            + std::to_string(r) + ";"
            + std::to_string(g) + ";"
            + std::to_string(b) + "m";
}

bool de::sisd(std::string str)
{
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool sisd_hex(std::string str)
{
    for (char c : str) {
        if (!isdigit(c)
         || (c >= 'a' && c <= 'f')
         || (c >= 'A' && c <= 'F')) {
            return false;
        }
    }
    return true;
}

bool sisd_bin(std::string str)
{
    for (char c : str) {
        if (c == '0' || c == '1') {
            return false;
        }
    }
    return true;
}

std::string de::signore(std::string str, char cign)
{
    std::string res;

    for (char c : str) {
        if (c == cign) continue;
        res += c;
    }

    return res;
}

std::string de::slise(std::string str, int start, int end)
{
    std::string res;

    if (end == -1) end = str.size();
    for (int i = start; i < end; i++) {
        res += str[i];
    } 
    return res;
}

template<typename T>
std::vector<T> de::slise(std::vector<T> vec, int start, int end)
{
    std::vector<T> res;

    if (end == -1) end = vec.size();
    for (int i = start; i < end; i++) {
        res.push_back(vec[i]);
    } 
    return res;
}

std::string de::trim(std::string str)
{
    if (str.empty()) return "";
    std::string res = "";
    u32 start = 0;
    u32 end = str.size()-1;

    while (str[start] == ' ') start++;
    while (str[end] == ' ')   end--;
    for (int i = start; i < end+1; i++) {
        res += str[i];
    }
    return res;
}

std::vector<std::string> de::split(std::string str, char splitter)
{
    std::vector<std::string> res {};
    std::string buf = "";

    for (char c : str) {
        if (c == splitter) {
            if (!buf.empty()) {
                res.push_back(buf);
                buf = "";
                continue;
            }
        }
        buf += c;
    }
    if (!buf.empty()) {
        res.push_back(buf);
    }
    return res;
}

std::string de::merge(std::vector<std::string> strs, char splitter)
{
    std::string res = "";
    std::string s = "";
    for (int i = 0; i < strs.size(); i++) {
        s = strs[i];
        res += s;
        if (i < strs.size() - 1) res += splitter;
    }
    return res;
}

std::string de::toc(std::string str, char C)
{
    std::string res = "";
    for (char c : str) {
        if (c == C) {
            return res;
        }
        res += c;
    }
    return res;
}

std::string de::aftc(std::string str, char C)
{
    int cp = 0;
    while (str[cp++] != C) {cp++;}
    return de::slise(str, cp, -1);
}

template<typename T>
void de::push_vec(std::vector<T> *vec, std::vector<T> new_vec)
{
    for (T el : new_vec) {
        vec->push_back(el);
    }
}

std::pair<std::string, std::string> de::twsplit(std::string str, char splitter)
{
    std::pair<std::string, std::string> res;

    int i = 0;
    for (; str[i] != splitter; i++) res.first += str[i];
    for (i++; i < str.size(); i++)  res.second += str[i];

    return res;
}