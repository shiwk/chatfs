#include "file.h"

namespace chatfs
{
    namespace file
    {
        sFile::sFile(p_path p)
        {
        }

        int sFile::read(p_outBuf b, size_t s, off_t o)
        {
            return 0;
        }

        int sFile::write(p_inBuf b, size_t s, off_t o)
        {
            return 0;
        }

        int mknod(p_path p, mode_t m, dev_t d)
        {
            return 0;
        }
    }
} // namespace chatfs