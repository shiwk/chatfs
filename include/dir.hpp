#ifndef DIR_HPP
#define DIR_HPP

#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 26
#endif

#include <fuse.h>
#include "common.hpp"

namespace chatfs
{
    namespace dir
    {
        struct sDir
        {
            sDir(path p);
            int list(outBuf b, fuse_fill_dir_t filler);
        };
        
        int mkdir(path p, mode_t m);
    } // namespace dir
} // namespace chatfs

#endif