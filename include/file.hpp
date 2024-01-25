#ifndef FILE_HPP
#define FILE_HPP

#include <sys/types.h>
#include "common.hpp"
#include "chatting.hpp"
#include <string>
namespace chatfs
{
    namespace file
    {
        struct sFile
        {
            sFile(path p) : path(p), content_("")
            {
                chatPtr = std::shared_ptr<chatfs::chat::Chating>(chatfs::chat::Chating::NewChat());
                std::string content;
                chatPtr->Send(p, content);
                write(content.data(), content.length(), 0);
            };
            int read(outBuf b, size_t s, off_t o);
            int write(inBuf b, size_t s, off_t o);
            int size();
            int truncate(off_t o);
            path path;

        private:
            std::string content_;
            size_t size_;
            std::shared_ptr<chatfs::chat::Chating> chatPtr;
        };
    }
} // namespace chatfs

#endif