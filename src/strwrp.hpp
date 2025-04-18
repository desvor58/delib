#include "delib.hpp"

// маленькая обертка над strcmp для удобства
inline bool streq(char *str1, char *str2)
{
    return strcmp(str1, str2) == 0;
}