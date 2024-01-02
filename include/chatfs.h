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
    using fuse_fi = struct fuse_file_info;
    /**
     * @brief Get attributes of file
     * @param p Path to file
     * @param st Stat struct to fill
    */
    int chatfs_get_attr(const char *p, s_stat *st);
    /**
     * @brief Read directory
     * @param p Path to directory
     * @param b Buffer to fill
     * @param filler Fuse filler function to fill buffer
     * @param offset Offsets of directory entries
     * @param fi Fuse file info
    */
    int chatfs_read_dir(const char *p, void *b, fuse_fill_dir_t filler, off_t offset, fuse_fi *fi);
    extern fuse_op chatfs_operations;
} // namespace chatfs


#endif