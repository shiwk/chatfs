#include "chatfs.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello, World." << std::endl;
    return fuse_main(argc, argv, &chatfs_operations, NULL);
}