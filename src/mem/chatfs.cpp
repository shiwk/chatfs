#include "chatfs.h"
#include "fsutil.h"
#include <iostream>
#include <unistd.h>

chatfs::fuse_op chatfs::chatfs_operations = {
    .getattr = chatfs::chatfs_get_attr,
    // .readdir = chatfs_readdir,
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
	st->st_uid = guid; // The owner of the file/directory is the user who mounted the filesystem
	st->st_gid = ggid; // The group of the file/directory is the same as the group of the user who mounted the filesystem
	st->st_atime = time( NULL ); // The last "a"ccess of the file/directory is right now
	st->st_mtime = time( NULL ); // The last "m"odification of the file/directory is right now
	
	if ( chatfs::fsutil::isDir(p))
	{
		st->st_mode = S_IFDIR | 0755;
		st->st_nlink = 2;
        return 0;
	}
	
    if ( chatfs::fsutil::isFile(p))
	{
		st->st_mode = S_IFREG | 0644;
		st->st_nlink = 1;
		st->st_size = 1024;
        return 0;
	}

    return CHATFSERR(ENOENT);
}