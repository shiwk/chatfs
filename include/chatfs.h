#ifndef CHATFS_HPP
#define CHATFS_HPP

#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 26
#endif
#include <fuse.h>

namespace chatfs
{
    #define CHATFSERR(ERR) -ERR
    using s_stat = struct stat;
    using fuse_op = struct fuse_operations;
    int chatfs_get_attr(const char *p, s_stat *st);
    extern fuse_op chatfs_operations;
} // namespace chatfs


#endif