#ifndef FILE_HPP
#define FILE_HPP

#include <sys/types.h>
#include "common.h"
#include <string>
namespace chatfs
{
    namespace file
    {
        struct sFile
        {
            sFile(p_path p) : path(p) { content_ = ""; };
            int read(p_outBuf b, size_t s, off_t o);
            int write(p_inBuf b, size_t s, off_t o);
            int size();
            int truncate(off_t o);
            p_path path;

        private:
            std::string content_;
            size_t size_;
        };
    }
} // namespace chatfs

#endif