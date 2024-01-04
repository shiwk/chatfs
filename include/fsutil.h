#ifndef FSUTIL_HPP
#define FSUTIL_HPP

#include <time.h>
#include "common.h"
namespace chatfs {
    namespace util {
        bool isDir(p_path);
        bool isFile(p_path);
        time_t timeNow();
    }
}

#endif