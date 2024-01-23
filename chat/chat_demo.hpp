#ifndef CHAT_DEMO_HPP
#define CHAT_DEMO_HPP

#include "chat.hpp"

namespace chatfs
{
    namespace chat
    {
        class TestChating : public Chating
        {
        public:
            bool send(const std::string req, std::string &resp) override;
        };
    } // namespace chat
} // namespace chatfs

#endif