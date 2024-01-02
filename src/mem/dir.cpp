# include "dir.h"


namespace chatfs
{
    namespace dir{
        sDir::sDir(const char *p)
        {
            
        }
        int sDir::list(void *b, fuse_fill_dir_t filler)
        {
            return 0;
        }
    }
} // namespace chatfs
