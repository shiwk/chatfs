#ifndef CHAT_BOT_HPP
#define CHAT_BOT_HPP

#include "chatting.hpp"
#include "chat_client.hpp"
#include <sstream>
#include <fstream>

namespace chatfs
{
    namespace chat
    {
        class ChatBot : public Chating
        {
        public:
            ChatBot(std::shared_ptr<ChatClient> client) : client_(client) {
                std::ifstream fJson("config.json");
                configBuf_ << fJson.rdbuf();
            }
            bool Send(const std::string& req, std::string &resp) override;
        private:
            void GenerateHeaderAndPostData(const std::string& send_msg);
            void ParseResponse(const std::string& resp, std::string& data);
            std::shared_ptr<ChatClient> client_;
            std::stringstream configBuf_;
        };
    } // namespace chat
} // namespace chatfs

#endif