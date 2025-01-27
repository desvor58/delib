#pragma once

#include <iostream>
#include <vector>

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
    /// @brief check if string is number
    /// @param str checkble string
    /// @return true if str is number, also return false

    // проверяет что строка являеться числом
    bool sisd(std::string str)
    {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    /// @brief remove from string choosed chars
    /// @param str sourse string
    /// @param cign char to ignore
    /// @return str without all char matching to cing

    // возвращает строку без символов cing
    std::string signore(std::string str, char cign)
    {
        std::string res;

        for (char c : str) {
            if (c == cign) continue;
            res += c;
        }

        return res;
    }

    /// @brief slise of string
    /// @param str sourse string
    /// @param start index start of slise
    /// @param end index end of slise (not be included in result string!!!)
    /// @return string slise from start index to end index

    // срез строки от start до end, не включая end
    std::string slise(std::string str, int start, int end)
    {
        std::string res;

        if (end == 0) end = str.size();
        for (int i = start; i < end; i++) {
            res += str[i];
        } 
        return res;
    }

    /// @brief return string without spaces in start and end
    /// @param str sourse string
    /// @return string without spaces in start and end

    // возвращает строку без пробелов в начале и конце
    std::string trim(std::string str)
    {
        std::string res = "";
        u32 start = 0;
        u32 end = str.size()-1;

        while (str[start] == ' ') start++;
        while (str[end] == ' ')   end--;
        for (int i = start; i < end; i++) {
            res += str[i];
        }
        return res;
    }

    // складывает a и b в пределах от minlimit до maxlimit
    int atl(int a, int b, int minlimit, int maxlimit)
    {
        if (a + b > maxlimit)
            return maxlimit;
        if (a + b < minlimit)
            return minlimit;
        return a + b;
    }

    // разделяет строку по символу splitter
    std::vector<std::string> split(std::string str, char splitter)
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
};