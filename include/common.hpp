#ifndef COMMON_HPP
#define COMMON_HPP

#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 26
#endif
#include <fuse.h>

namespace chatfs
{
    #define __CHATFSERR__(ERR) -ERR
    
    using s_stat = struct stat;
    using s_fuseOp = struct fuse_operations;
    using s_fuseFI = struct fuse_file_info;
    using path = const char *;
    using outBuf = char *;
    using inBuf = const char *;
} // namespace chatfs

#endif