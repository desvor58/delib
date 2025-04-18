#pragma once

#include <fstream>
#include <string>
#include "delib.hpp"

namespace de
{
    // возвращает текст файла как строку
    std::string file_get_text(std::string name);

    // возвращает байты файла как вектор
    std::vector<u8> file_get_bytes(std::string name);

    // возвращает вектор строк файла
    std::vector<std::string> file_get_lines(std::string name);

    // возвращает путь до файла, без названия самого файла
    std::string get_file_path(std::string name);
}

std::string de::file_get_text(std::string name)
{
    std::string res = "";
    std::ifstream file(name);
    if (!file.is_open()) {
        throw std::string("file not be open (")
            + name + std::string(")");
    }
    char c = 0;
    while (file.get(c)) {
        res += c;
    }
    file.close();
    return res;
}

std::vector<u8> de::file_get_bytes(std::string name)
{
    std::vector<u8> res;
    std::ifstream file(name, std::ios::binary);
    if (!file.is_open()) {
        throw std::string("file not be open (")
            + name + std::string(")");
    }
    char c;
    while (file.get(c)) {
        res.push_back(c);
    }
    file.close();
    return res;
}

std::vector<std::string> de::file_get_lines(std::string name)
{
    std::vector<std::string> res {};
    std::string line {};
    std::ifstream file(name);
    if (!file.is_open()) {
        throw std::string("file not be open (")
            + name + std::string(")");
    }
    char c;
    while (file.get(c)) {
        if (c == '\n') {
            res.push_back(line);
            line.clear();
            continue;
        }
        line += c;
    }
    res.push_back(line);
    file.close();
    return res;
}

std::string de::get_file_path(std::string path)
{
    int i = path.size()-1;
    while (path[i] != '/') {i--;}
    return de::slise(path, 0, i+1);
}