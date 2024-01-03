#include "fsutil.h"

namespace chatfs
{
    namespace fsutil
    {
        bool isDir(p_path p)
        {
            return false;
        }
        bool isFile(p_path p)
        {
            return false;
        }
        time_t timeNow()
        {
            return time(nullptr);
        }
    }
}