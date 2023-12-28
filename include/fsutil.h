#ifndef FSUTIL_HPP
#define FSUTIL_HPP

#include <time.h>
namespace chatfs {
    namespace fsutil {
        bool isDir(const char *p);
        bool isFile(const char *p);
        time_t timeNow();
    }
}

#endif