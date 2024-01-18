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
    std::cout << "begin read chatfs attr " << p << std::endl;
    st->st_uid = guid;
    st->st_gid = ggid;
    time_t now = chatfs::util::timeNow();
    st->st_atime = now;
    st->st_mtime = now;
    if (chatfs::util::isDir(p))
    {
        st->st_mode = S_IFDIR | 0755; // change mode drwxrwxr-x
        st->st_nlink = 2;
        std::cout << "end read dir attr " << p << std::endl;
        return 0;
    }
    
    std::shared_ptr<chatfs::file::sFile> filePtr;
    if (chatfs::util::GetFile(p, filePtr))
    {
        st->st_mode = S_IFREG | 0644; // change mode -rw-r--r--
        st->st_nlink = 1;
        st->st_size = filePtr->size();
        std::cout << "end read file attr " << p << std::endl;
        return 0;
    }
    
    std::cout << "No such directory or file: " << p << std::endl;
    return __CHATFSERR__(ENOENT);
}

int chatfs::chatfs_read_dir(const char * p, void *b, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi)
{
    std::cout << "begin read chatfs dir " << p << std::endl;
    if (chatfs::util::listDir(p, b, filler) != 0)
        return __CHATFSERR__(ENOENT);
    std::cout << "end read chatfs dir " << p << std::endl;
    return 0;
}


int chatfs::chatfs_mkdir(p_path p, mode_t m)
{
    std::cout << "begin mkdir " << p << std::endl;
    int ret = chatfs::util::mkDir(p, m);
    std::cout << "end mkdir " << p << std::endl;
    return ret == 0 ? 0 : __CHATFSERR__(ret);
}

int chatfs::chatfs_mknod(p_path p, mode_t m, dev_t d)
{
    std::cout << "begin mknod " << p << std::endl;
    int ret = chatfs::util::mkNod(p, m, d);
    std::cout << "end mknod " << p << std::endl;
    return ret == 0 ? 0 : __CHATFSERR__(ret);
}

int chatfs::chatfs_read_file(p_path p, p_outBuf b, size_t size, off_t offset, s_fuseFI *fi)
{
    std::cout << "begin read chatfs file " << p << std::endl;
    int ret = chatfs::util::read(p, b, size, offset, fi);
    std::cout << "end read chatfs file " << p << std::endl;
    return ret >= 0 ? ret : __CHATFSERR__(ret);
}

int chatfs::chatfs_write_file(p_path p, p_inBuf b, size_t size, off_t offset, s_fuseFI *fi)
{
    std::cout << "begin write file " << p << std::endl;
    int ret = chatfs::util::write(p, b, size, offset, fi);
    std::cout << "end write file " << p << std::endl;
    return ret >= 0 ? ret : __CHATFSERR__(ret);
}
