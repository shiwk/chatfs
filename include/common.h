#ifndef COMMON_HPP
#define COMMON_HPP

#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 26
#endif

namespace chatfs
{
    #define __CHATFSERR__(ERR) -ERR
    
    using s_stat = struct stat;
    using s_fuseOp = struct fuse_operations;
    using s_fuseFI = struct fuse_file_info;
    using p_path = const char *;
    using p_outBuf = char *;
    using p_inBuf = const char *;
} // namespace chatfs

#endif