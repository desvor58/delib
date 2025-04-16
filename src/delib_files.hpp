#pragma once

#include <fstream>
#include "delib.hpp"

namespace de
{
    // возвращает текст файла как строку
    std::string file_get_text(std::string name);

    // возвращает байты файла как вектор
    std::vector<u8> file_get_bytes(std::string name);

    // возвращает вектор строк файла
    std::vector<std::string> file_get_lines(std::string name);
}
