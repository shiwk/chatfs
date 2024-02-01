#include "file.hpp"
#include <iostream>

namespace chatfs
{
    namespace file
    {

        int sFile::read(outBuf b, size_t s, off_t off)
        {
            if (off >= content_.size())
            {
                return 0;
            }
            memcpy(b, content_.data() + off, s);
            size_t len = content_.size() - off;
            //std::cout << "read " << b << " from " << path << std::endl;
            //std::cout << "read len: " << len << std::endl;
            return len;
        }

        int sFile::write(inBuf b, size_t s, off_t o)
        {
            //std::cout << "write " << b << " to " << path << std::endl;
            content_.assign(b, s);
            //std::cout << "write len:" << content_.size() << std::endl;
            size_ = content_.size();
            return size_;
        }

        int sFile::size()
        {
            return size_;
        }

        int sFile::truncate(off_t o)
        {
            size_ = o;
            return 0;
        }
    }
} // namespace chatfs