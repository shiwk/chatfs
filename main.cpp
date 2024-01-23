#include "chatfs.hpp"
#include <iostream>
#include <fuse.h>


static struct fuse_operations chatfs_operations = {
    // .getattr = do_getattr,
    .getattr = chatfs::chatfs_get_attr,
    .readdir = chatfs::chatfs_read_dir,
    .mkdir = chatfs::chatfs_mkdir,
    .mknod = chatfs::chatfs_mknod,
    .write = chatfs::chatfs_write_file,
    .read = chatfs::chatfs_read_file,
    .truncate = chatfs::chatfs_truncate,
    .unlink = chatfs::chatfs_unlink
};

int main(int argc, char *argv[])
{
    std::cout << "Hello, World." << std::endl;
    return fuse_main(argc, argv, &chatfs_operations, NULL);
}