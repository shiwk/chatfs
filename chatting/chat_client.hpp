#ifndef CLIENT_CURL_HPP
#define CLIENT_CURL_HPP

#include <curl/curl.h>
#include <string>
#include <iostream>

namespace chatfs
{

    class ChatClient
    {
    public:
        ChatClient();
        ~ChatClient();
        bool Send(const std::string &, std::string &);

    private:
        CURL *curl_ = nullptr;
        static size_t WriteRecvMsg(void *content, size_t mem_block_size, size_t mem_block_num, void *user_stuc);
    };

}

#endif