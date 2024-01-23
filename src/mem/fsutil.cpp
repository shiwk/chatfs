#include "fsutil.hpp"
#include "file.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

static std::vector<std::string> dirs;
// static std::vector<std::string> files;
static std::unordered_map<std::string, std::string> fileContents;
static std::unordered_map<std::string, std::shared_ptr<chatfs::file::sFile>> fileMap;

namespace chatfs
{
    namespace util
    {
        bool isDir(path p)
        {
            if (strcmp(p, "/") == 0)
                return true;

            for (auto d : dirs)
            {
                if (strcmp(p + 1, d.data()) == 0)
                    return true;
            }

            return false;
        }
        bool isFile(path p)
        {
            if (strcmp(p, "/") == 0)
                return false;

            return fileMap.find(p + 1) != fileMap.end();
        }

        bool GetFile(path p, std::shared_ptr<chatfs::file::sFile> &filePtr)
        {
            if (!isFile(p))
                return false;
            
            filePtr = fileMap[p + 1];
            return true;
        }

        int mkDir(path p, mode_t m)
        {
            if (isDir(p) || isFile(p))
            {
                return EEXIST;
            }
            std::cout << "new dir:" << p + 1 << std::endl;
            dirs.emplace_back(p + 1);
            return 0;
        }

        int mkNod(path p, mode_t m, dev_t d)
        {
            if (isDir(p) || isFile(p))
            {
                return EEXIST;
            }

            std::cout << "new file:" << p + 1 << std::endl;
            file::sFile *file = new file::sFile(p + 1);
            fileMap.emplace(p + 1, file);
            return 0;
        }

        int listDir(path p, void *b, fuse_fill_dir_t fill)
        {
            fill(b, ".", NULL, 0);  // Current Directory
            fill(b, "..", NULL, 0); // Parent Directory

            if (strcmp(p, "/") != 0)
            {
                // TODO: subdirectory listing
                return 0;
            }

            for (auto d : dirs)
            {
                std::cout << "dir:" << d << std::endl;
                fill(b, d.data(), NULL, 0);
            }

            for (auto f : fileMap)
            {
                std::cout << "file:" << f.first << std::endl;
                fill(b, f.first.data(), NULL, 0);
            }

            return 0;
        }

        int read(path p, outBuf b, size_t s, off_t off, s_fuseFI *)
        {
            if (!isFile(p))
            {
                return ENOENT;
            }

            auto file = fileMap[p + 1];
            return file->read(b, s, off);
        }

        int write(path p, inBuf b, size_t s, off_t off, s_fuseFI *fi)
        {
            if (!isFile(p))
            {
                return ENOENT;
            }
            auto file = fileMap[p + 1];
            return file->write(b, s, off);
        }

        int truncate(path p, off_t offset)
        {
            if (!isFile(p))
            {
                return ENOENT;
            }
            auto file = fileMap[p + 1];
            return file->truncate(offset);
        }

        int unlink(path p)
        {
            if (!isFile(p))
            {
                return ENOENT;
            }
            fileMap.erase(p + 1);
            return 0;
        }

        time_t timeNow()
        {
            return time(nullptr);
        }
    }
}