#ifndef CHAT_DEMO_HPP
#define CHAT_DEMO_HPP

#include "chatting.hpp"
#include "chat_client.hpp"

namespace chatfs
{
    namespace chat
    {
        class ChatBot : public Chating
        {
        public:
            ChatBot(std::shared_ptr<ChatClient> client) : client_(client) {}
            bool Send(const std::string req, std::string &resp) override;
        private:
            std::shared_ptr<ChatClient> client_;
        };
    } // namespace chat
} // namespace chatfs

#endif