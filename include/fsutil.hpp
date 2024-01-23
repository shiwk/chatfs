#ifndef FSUTIL_HPP
#define FSUTIL_HPP

#include <time.h>
#include "file.hpp"
#include <sys/types.h>
#include <fuse.h>

namespace chatfs
{
    namespace util
    {
        bool isDir(path);
        bool isFile(path);
        bool GetFile(path p, std::shared_ptr<chatfs::file::sFile> &filePtr);
        int mkDir(path, mode_t);
        int mkNod(path, mode_t, dev_t);
        int listDir(path, void *, fuse_fill_dir_t);
        int read(path, outBuf, size_t, off_t, s_fuseFI *);
        int write(path, inBuf, size_t, off_t, s_fuseFI *);
        int truncate(path, off_t);
        int unlink(path);
        time_t timeNow();
    }
}

#endif