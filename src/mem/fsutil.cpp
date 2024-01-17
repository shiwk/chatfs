#include "fsutil.h"
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>


static std::vector<std::string> dirs;
static std::vector<std::string> files;
static std::unordered_map<std::string, std::string> fileContents;

namespace chatfs
{
    namespace util
    {
        bool isDir(p_path p)
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
        bool isFile(p_path p)
        {
            for (auto f : files)
            {
                if (strcmp(p + 1, f.data()) == 0)
                    return true;
            }
            return false;
        }

        int mkDir(p_path p, mode_t m)
        {
            if (isDir(p) || isFile(p))
            {
                return EEXIST;
            }
            ++p;
            std::cout << "new dir:" << p << std::endl;
            dirs.emplace_back(p);
            return 0;
        }

        int mkNod(p_path p, mode_t m, dev_t d)
        {
            if (isDir(p) || isFile(p))
            {
                return EEXIST;
            }

            ++p;
            std::cout << "new file:" << p << std::endl;
            files.emplace_back(p);
            return 0;
        }

        int listDir(p_path p, void* b, fuse_fill_dir_t fill)
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

            for (auto f : files)
            {
                std::cout << "file:" << f << std::endl;
                fill(b, f.data(), NULL, 0);
            }

            return 0;

        }

        int read(p_path p, p_outBuf b, size_t s, off_t off, s_fuseFI *)
        {
            if (!isFile(p))
            {
                return ENOENT;
            }

            if (fileContents.find(p) == fileContents.end())
            {
                return 0;
            }
            
            memcpy(b, fileContents[p].data() + off, s);

            return fileContents[p].size() - off;
        }

        int write(p_path p, p_inBuf b, size_t s, off_t off, s_fuseFI * fi)
        {
            if (!isFile(p))
            {
                return ENOENT;
            }
            fileContents.emplace(p, b);
            return 0;
        }

        time_t timeNow()
        {
            return time(nullptr);
        }
    }
}