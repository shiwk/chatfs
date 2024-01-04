#include "chatfs.h"
#include "fsutil.h"
#include "dir.h"
#include "file.h"
#include <iostream>
#include <unistd.h>

chatfs::s_fuseOp chatfs::chatfs_operations = {
    .getattr = chatfs::chatfs_get_attr,
    .readdir = chatfs::chatfs_read_dir,
    .read = chatfs::chatfs_read_file,
    .mkdir = chatfs::chatfs_mkdir,
    .mknod = chatfs::chatfs_mknod,
    .write = chatfs::chatfs_write_file,
    // .open = chatfs_open,
    // .release = chatfs_release,
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

int chatfs::chatfs_get_attr(p_path p, s_stat *st)
{
    if (util::isDir(p))
    {
        st->st_mode = S_IFDIR | 0755; // change mode drwxrwxr-x
        st->st_nlink = 2;
        return 0;
    }

    if (util::isFile(p))
    {
        st->st_mode = S_IFREG | 0644; // change mode -rw-r--r--
        st->st_nlink = 1;
        st->st_size = 1024;
        return 0;
    }
    st->st_uid = guid;
    st->st_gid = ggid;
    time_t now = util::timeNow();
    st->st_atime = now;
    st->st_mtime = now;

    return __CHATFSERR__(ENOENT);
}

int chatfs::chatfs_read_dir(p_path p, void *b, fuse_fill_dir_t filler, off_t offset, chatfs::s_fuseFI *fi)
{
    if (!util::isDir(p))
        return __CHATFSERR__(ENOTDIR);

    std::shared_ptr<dir::sDir> cur(new dir::sDir(p));
    return cur->list((p_outBuf)b, filler);
}

int chatfs::chatfs_read_file(p_path p, p_outBuf b, size_t size, off_t offset, s_fuseFI *fi)
{
    if (!util::isFile(p))
        return __CHATFSERR__(ENOTDIR);

    std::shared_ptr<file::sFile> cur(new file::sFile(p));
    return cur->read(b, size, offset);
}

int chatfs::chatfs_mkdir(p_path p, mode_t m)
{
    return dir::mkdir(p, m);
}

int chatfs::chatfs_mknod(p_path p, mode_t m, dev_t d)
{
    return file::mknod(p, m, d);
}

int chatfs::chatfs_write_file(p_path p, p_inBuf b, size_t size, off_t offset, s_fuseFI *fi)
{
    if (!util::isFile(p))
        return __CHATFSERR__(ENOTDIR);
    
    std::shared_ptr<file::sFile> cur(new file::sFile(p));
    return cur->write(b, size, offset);
    return 0;
}
