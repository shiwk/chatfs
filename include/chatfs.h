#ifndef CHATFS_HPP
#define CHATFS_HPP

#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 26
#endif
#include <fuse.h>
extern int chatfs_getattr(const char *p, struct stat *st);
extern struct fuse_operations chatfs_operations;

#endif