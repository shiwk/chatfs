#include "chat_bot.hpp"
#include <iostream>

bool chatfs::chat::ChatBot::Send(const std::string send_msg, std::string &recv_msg)
{
    // todo: \
        fuse: read too many bytes \
        fuse: writing device: Invalid argument
    const std::string url = "https://github.com/shiwk/chatfs";
    bool res = client_->Send(url, recv_msg);
    assert(res);
    std::cout << "recv_msg:" << recv_msg << std::endl;
    return true;
}

chatfs::chat::Chating *chatfs::chat::Chating::NewChat()
{
    return new ChatBot(std::make_shared<ChatClient>());
}
