#ifndef FSUTIL_HPP
#define FSUTIL_HPP

#include <time.h>
#include "common.h"
#include <sys/types.h>
#include <fuse.h>

namespace chatfs {
    namespace util {
        bool isDir(p_path);
        bool isFile(p_path);
        int mkDir(p_path, mode_t);
        int listDir(p_path, void*, fuse_fill_dir_t);
        time_t timeNow();
    }
}

#endif