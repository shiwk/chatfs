#include "fsutil.h"
#include <vector>

static std::vector<chatfs::p_path> dirs;
static std::vector<chatfs::p_path> files;

namespace chatfs
{
    namespace util
    {
        bool isDir(p_path p)
        {
            if (strcmp(p, "/") == 0)
                return true;

            for (auto i : dirs)
            {
                if (strcmp(p + 1, i) == 0)
                    return true;
            }
            
            return false;
        }
        bool isFile(p_path p)
        {
            for (auto i : files)
            {
                if (strcmp(p + 1, i) == 0)
                    return true;
            }
            return false;
        }

        int mkDir(p_path p, mode_t m)
        {
            if (isDir(p) || isFile(p))
            {
                return EEXIST;
            }
            dirs.push_back(p);
            return 0;
        }

        int listDir(p_path p, void* b, fuse_fill_dir_t f)
        {
            f(b, ".", NULL, 0);  // Current Directory
            f(b, "..", NULL, 0); // Parent Directory

            if (strcmp(p, "/") != 0)
            {
                // TODO: subdirectory listing
                return 0;
            }

            for (auto i : dirs)
            {
                f(b, i, NULL, 0);
            }

            for (auto i : files)
            {
                f(b, i, NULL, 0);
            }

            return 0;

        }

        time_t timeNow()
        {
            return time(nullptr);
        }
    }
}