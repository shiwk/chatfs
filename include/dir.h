#ifndef DIR_HPP
#define DIR_HPP

#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 26
#endif

#include <fuse.h>
#include "common.h"

namespace chatfs
{
    namespace dir
    {
        struct sDir
        {
            sDir(p_path p);
            int list(p_outBuf b, fuse_fill_dir_t filler);
        };
        
        int mkdir(p_path p, mode_t m);
    } // namespace dir
} // namespace chatfs

#endif