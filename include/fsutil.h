#ifndef FSUTIL_HPP
#define FSUTIL_HPP

#include <time.h>
#include "file.h"
#include <sys/types.h>
#include <fuse.h>

namespace chatfs
{
    namespace util
    {
        bool isDir(p_path);
        bool isFile(p_path);
        bool GetFile(p_path p, std::shared_ptr<chatfs::file::sFile> &filePtr);
        int mkDir(p_path, mode_t);
        int mkNod(p_path, mode_t, dev_t);
        int listDir(p_path, void *, fuse_fill_dir_t);
        int read(p_path, p_outBuf, size_t, off_t, s_fuseFI *);
        int write(p_path, p_inBuf, size_t, off_t, s_fuseFI *);
        int truncate(p_path, off_t);
        int unlink(p_path);
        time_t timeNow();
    }
}

#endif