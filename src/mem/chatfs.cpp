#include "chatfs.h"
#include "fsutil.h"
#include "dir.h"
#include "file.h"
#include <iostream>
#include <unistd.h>

static uid_t guid = getuid();
static gid_t ggid = getgid();

int chatfs::chatfs_get_attr(p_path p, s_stat *st)
{
    std::cout << "read chatfs file " << p << std::endl;
    if (chatfs::util::isDir(p))
    {
        st->st_mode = S_IFDIR | 0755; // change mode drwxrwxr-x
        st->st_nlink = 2;
        return 0;
    }

    if (chatfs::util::isFile(p))
    {
        st->st_mode = S_IFREG | 0644; // change mode -rw-r--r--
        st->st_nlink = 1;
        st->st_size = 1024;
        return 0;
    }
    st->st_uid = guid;
    st->st_gid = ggid;
    time_t now = chatfs::util::timeNow();
    st->st_atime = now;
    st->st_mtime = now;

    return __CHATFSERR__(ENOENT);
}

int chatfs::chatfs_read_dir(const char * p, void *b, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi)
{
    std::cout << "read chatfs dir " << p << std::endl;
    if (!chatfs::util::isDir(p))
        return __CHATFSERR__(ENOTDIR);

    std::shared_ptr<chatfs::dir::sDir> cur(new chatfs::dir::sDir(p));
    return cur->list((char *)b, filler);
}

int chatfs::chatfs_read_file(p_path p, p_outBuf b, size_t size, off_t offset, s_fuseFI *fi)
{
    if (!chatfs::util::isFile(p))
        return __CHATFSERR__(ENOTDIR);

    std::shared_ptr<chatfs::file::sFile> cur(new chatfs::file::sFile(p));
    return cur->read(b, size, offset);
}

int chatfs::chatfs_mkdir(p_path p, mode_t m)
{
    std::cout << "mkdir " << p << std::endl;
    return chatfs::dir::mkdir(p, m);
}

int chatfs::chatfs_mknod(p_path p, mode_t m, dev_t d)
{
    return chatfs::file::mknod(p, m, d);
}

int chatfs::chatfs_write_file(p_path p, p_inBuf b, size_t size, off_t offset, s_fuseFI *fi)
{
    if (!chatfs::util::isFile(p))
        return __CHATFSERR__(ENOTDIR);
    
    std::shared_ptr<chatfs::file::sFile> cur(new chatfs::file::sFile(p));
    return cur->write(b, size, offset);
    return 0;
}
