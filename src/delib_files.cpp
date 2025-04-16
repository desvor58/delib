#include "delib_files.hpp"

std::string de::file_get_text(std::string name)
{
    std::string res;
    std::ifstream file(name);
    if (!file.is_open()) {
        throw std::string("file not be open (")
            + name + std::string(")");
    }
    char c;
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