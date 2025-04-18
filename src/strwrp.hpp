#include "delib.hpp"

#ifdef USESHORTNAMES
    typedef std::string str
    typedef std::vector vec
#endif

namespace de
{
    // маленькая обертка над strcmp для удобства
    inline bool streq(char *str1, char *str2)
    {
        return strcmp(str1, str2) == 0;
    }
}