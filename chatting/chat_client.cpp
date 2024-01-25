#include "chat_client.hpp"

chatfs::ChatClient::ChatClient()
{
    curl_global_init(CURL_GLOBAL_ALL);
    curl_ = curl_easy_init();
}

chatfs::ChatClient::~ChatClient()
{
    curl_easy_cleanup(curl_);
}

bool chatfs::ChatClient::Send(const std::string &url, std::string &response)
{
    if (!curl_)
    {
        return false;
    }

    curl_easy_setopt(curl_, CURLOPT_URL, url.data());
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, &WriteRecvMsg);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl_);
    if (res != CURLE_OK)
    {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }
    return (res == CURLE_OK);
}

size_t chatfs::ChatClient::WriteRecvMsg(void *content, size_t mem_block_size, size_t mem_block_num, void *user_stuc)
{
    size_t contentSize = mem_block_size * mem_block_num;
    std::string *str = static_cast<std::string *>(user_stuc);
    str->append(static_cast<char *>(content), contentSize);
    return contentSize;
}
