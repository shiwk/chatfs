#ifndef CHATFS_HPP
#define CHATFS_HPP

#include "common.hpp"

namespace chatfs
{
    /**
     * @brief Get attributes of file
     * @param p Path to file
     * @param st Stat struct to fill
     * @return 0 on success, -1 on failure
    */
    int chatfs_get_attr(path, s_stat *st);
    /**
     * @brief Read directory
     * @param p Path to directory
     * @param b Buffer to fill
     * @param filler Fuse filler function to fill buffer
     * @param offset Offsets of directory entries
     * @param fi Fuse file info
     * @return 0 on success, -1 on failure
    */
    int chatfs_read_dir(path, void *b, fuse_fill_dir_t filler, off_t, s_fuseFI *fi);

    /**
     * @brief Read file
     * @param p Path to file
     * @param b Buffer to fill
     * @param size Size of buffer
     * @param offset Offset of file
     * @param fi Fuse file info
     * @return Number of bytes read
    */
    int chatfs_read_file(path, outBuf, size_t, off_t, s_fuseFI *fi);

    /**
     * @brief mkdir
     * @param p Path to dir
     * @param m Mode of dir
     * @return 0 on success, -1 on failure
    */
    int chatfs_mkdir(path, mode_t);

    /**
     * @brief Create file
     * @param p Path to file
     * @param m Mode of file
     * @param d Device of file
     * @return 0 on success, -1 on failure
    */
    int chatfs_mknod(path, mode_t, dev_t);

    /**
     * @brief Write file
     * @param p Path to file
     * @param b Buffer to write
     * @param size Size of buffer
     * @param offset Offset of file
     * @param fi Fuse file info
     * @return Number of bytes written
    */
    int chatfs_write_file(path, inBuf, size_t, off_t, s_fuseFI *fi);

    /**
     * @brief Truncate file
     * @param p Path to file
     * @param o Offset of file
     * @return 0 on success, -1 on failure
    */
    int chatfs_truncate(path, off_t);

    /**
     * @brief Unlink file
     * @param p Path to file
     * @return 0 on success, -1 on failure
    */
    int chatfs_unlink(path);
} // namespace chatfs


#endif