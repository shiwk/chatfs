#include "chat_demo.hpp"

bool chatfs::chat::TestChating::send(const std::string req, std::string &resp)
{
    resp = req;
    return true;
}

chatfs::chat::Chating *chatfs::chat::Chating::newChat()
{
    return new TestChating();
}
