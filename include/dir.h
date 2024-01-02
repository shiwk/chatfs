#ifndef DIR_HPP
#define DIR_HPP

#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 26
#endif

#include <fuse.h>

namespace chatfs
{
    namespace dir{
        struct sDir
        {
            sDir(const char *p);
            int list(void *b, fuse_fill_dir_t filler);
        };
    }
    
} // namespace chatfs


#endif