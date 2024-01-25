#include "chat_bot.hpp"
#include <iostream>

bool chatfs::chat::ChatBot::send(const std::string send_msg, std::string &recv_msg)
{
    // todo: implement chat request
    // resp.assign(req);
    // resp.append(1, '\n');
    const std::string url = "https://www.github.com";
    client_->Get(url, recv_msg);
    std::cout << 'recv_msg' << recv_msg << std::endl;
    return true;
}

chatfs::chat::Chating *chatfs::chat::Chating::newChat()
{
    return new ChatBot(std::make_shared<ChatClient>());
}
