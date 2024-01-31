#ifndef CLIENT_CLIENT_HPP
#define CLIENT_CLIENT_HPP

#include <curl/curl.h>
#include <string>
#include <iostream>
#include <vector>

namespace chatfs
{

    class ChatClient
    {
    public:
        ChatClient();
        ~ChatClient();
        bool Request(std::string &resp);
        void SetUrl(const std::string &url);
        void AddHeader(const std::string &header);
        void SetJsonData(const std::string &json_data);
    private:
        CURL *curl_ = nullptr;
        std::string url_;
        std::vector<std::string> headers_;
        std::string json_data_;
        static size_t WriteRecvMsg(void *content, size_t mem_block_size, size_t mem_block_num, void *user_stuc);
    };

}

#endif