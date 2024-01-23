#include "dir.hpp"

namespace chatfs
{
    namespace dir
    {
        sDir::sDir(path p)
        {
        }
        int sDir::list(outBuf b, fuse_fill_dir_t filler)
        {
            return 0;
        }

        int mkdir(path p, mode_t m)
        {
            return 0;
        }
    }
} // namespace chatfs
