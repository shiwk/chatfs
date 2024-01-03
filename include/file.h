#ifndef FILE_HPP
#define FILE_HPP

#include <sys/types.h>
#include "common.h" 
namespace chatfs
{
    namespace file
    {
        struct sFile
        {
            sFile(p_path p);
            int read(p_outBuf b, size_t s, off_t o);
            int write(p_inBuf b, size_t s, off_t o);
        };
        
        int mknod(p_path p, mode_t m, dev_t d);
    }
} // namespace chatfs

#endif