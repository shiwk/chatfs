#include "chat_demo.hpp"

bool chatfs::chat::TestChating::send(const std::string req, std::string &resp)
{
    // todo: implement chat request
    resp.assign(req);
    resp.append(1, '\n');
    return true;
}

chatfs::chat::Chating *chatfs::chat::Chating::newChat()
{
    return new TestChating();
}
