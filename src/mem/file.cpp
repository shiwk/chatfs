#include "file.h"
#include <iostream>

namespace chatfs
{
    namespace file
    {

        int sFile::read(p_outBuf b, size_t s, off_t off)
        {
            std::cout << "read " << b << " from " << path << std::endl;
            if (off >= content.size())
            {
                return 0;
            }
            memcpy(b, content.data() + off, s);
            size_t len = content.size() - off;
            std::cout<<  "read len: " << len << std::endl;
            return len;
        }

        int sFile::write(p_inBuf b, size_t s, off_t o)
        {
            std::cout << "write " << b << " to " << path << std::endl;
            content = b;
            std::cout << "write len:" << content.size() << std::endl;
            return content.size();
        }

        int sFile::size()
        {
            return content.size();
        }
    }
} // namespace chatfs