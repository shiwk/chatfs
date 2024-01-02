#include "chatfs.h"
#include "fsutil.h"
#include "dir.h"
#include <iostream>
#include <unistd.h>


chatfs::fuse_op chatfs::chatfs_operations = {
    .getattr = chatfs::chatfs_get_attr,
    .readdir = chatfs::chatfs_read_dir,
    // .open = chatfs_open,
    // .read = chatfs_read,
    // .write = chatfs_write,
    // .release = chatfs_release,
    // .mkdir = chatfs_mkdir,
    // .rmdir = chatfs_rmdir,
    // .unlink = chatfs_unlink,
    // .rename = chatfs_rename,
    // .create = chatfs_create,
    // .utimens = chatfs_utimens,
    // .truncate = chatfs_truncate,
    // .chmod = chatfs_chmod,
    // .chown = chatfs_chown,
    // .link = chatfs_link,
    // .symlink = chatfs_symlink,
    // .readlink = chatfs_readlink,
    // .statfs = chatfs_statfs,
    // .destroy = chatfs_destroy,
    // .access = chatfs_access,
    // .flush = chatfs_flush,
    // .fsync = chatfs_fsync,
    // .fsyncdir = chatfs_fsyncdir,
    // .lock = chatfs_lock,
    // .flock = chatfs_flock,
    // .fallocate = chatfs_fallocate,
    // .setxattr = chatfs_setxattr,
    // .getxattr = chatfs_getxattr,
    // .listxattr = chatfs_listxattr,
    // .removexattr = chatfs_removexattr,
    // .opendir = chatfs_opendir,
    // .releasedir = chatfs_releasedir,
    // .fsyncdir = chatfs_fsyncdir,
    // .init = chatfs_init,
    // .truncate = chatfs_truncate,
    // .ioctl = chatfs_ioctl,
    // .poll = chatfs_poll,
    // .write_buf = chatfs_write_buf,
    // .read_buf = chatfs_read_buf,
    // .flock = chatfs_flock,
    // .fallocate = chatfs_fallocate,
    // .readdirplus = chatfs_readdirplus,
    // .copy_file_range = chatfs_copy_file_range,
    // .lseek = chatfs_lseek,
    // .destroy = chatfs_destroy,
    // .access = chatfs_access,
    // .create = chatfs_create,
    // .getlk = chatfs_getlk,
    // .setlk = chatfs_setlk,
    // .bmap = chatfs_bmap,
    // .ioctl = chat
};

static uid_t guid = getuid();
static gid_t ggid = getgid();

int chatfs::chatfs_get_attr(const char *p, s_stat *st)
{
    if (fsutil::isDir(p))
    {
        st->st_mode = S_IFDIR | 0755; // change mode drwxrwxr-x
        st->st_nlink = 2;
        return 0;
    }

    if (fsutil::isFile(p))
    {
        st->st_mode = S_IFREG | 0644; // change mode -rw-r--r--
        st->st_nlink = 1;
        st->st_size = 1024;
        return 0;
    }
    st->st_uid = guid;
    st->st_gid = ggid;
    time_t now = fsutil::timeNow();
    st->st_atime = now;
    st->st_mtime = now;

    return CHATFSERR(ENOENT);
}

int chatfs::chatfs_read_dir(const char *p, void *b, fuse_fill_dir_t filler, off_t offset, chatfs::fuse_fi *fi)
{
    if (!fsutil::isDir(p))
        return CHATFSERR(ENOTDIR);
    
    std::shared_ptr<dir::sDir> cur (new dir::sDir(p));
    return cur->list(b, filler);
}

