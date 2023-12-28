#include "fsutil.h"


namespace chatfs {
    namespace fsutil {
        bool isDir(const char *p) {
            return false;
        }
        bool isFile(const char *p) {
            return false;
        }
        time_t timeNow()
        {
            return time(nullptr);
        }
    }
}