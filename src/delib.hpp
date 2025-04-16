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
