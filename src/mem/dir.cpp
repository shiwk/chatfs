#include "dir.h"

namespace chatfs
{
    namespace dir
    {
        sDir::sDir(p_path p)
        {
        }
        int sDir::list(p_outBuf b, fuse_fill_dir_t filler)
        {
            return 0;
        }

        int mkdir(p_path p, mode_t m)
        {
            return 0;
        }
    }
} // namespace chatfs
