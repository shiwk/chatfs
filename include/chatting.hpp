#ifndef CHAT_HPP
#define CHAT_HPP

#include <string>

namespace chatfs{
    namespace chat{
        class Chating{
            public:
                virtual bool send(const std::string req, std::string& resp) = 0;
                static Chating* newChat();
        };
    }
}

#endif