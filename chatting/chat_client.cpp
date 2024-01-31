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

void chatfs::ChatClient::SetUrl(const std::string &url)
{
    url_ = url;
}

void chatfs::ChatClient::AddHeader(const std::string &header)
{
    headers_.push_back(header);
}

void chatfs::ChatClient::SetJsonData(const std::string &json_data)
{
    json_data_ = json_data;
}

bool chatfs::ChatClient::Request(std::string &response)
{
    if (!curl_)
    {
        return false;
    }

    curl_easy_setopt(curl_, CURLOPT_URL, url_.data());
    curl_easy_setopt(curl_, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl_, CURLOPT_POST, 1L);
    //header
    struct curl_slist* chunk = NULL;
    for (const auto &header : headers_)
    {
        chunk = curl_slist_append(chunk, header.data());
    }
    curl_easy_setopt(curl_, CURLOPT_HTTPHEADER, chunk);
    
    // set the POST size and content
    
    curl_easy_setopt(curl_, CURLOPT_POSTFIELDSIZE, json_data_.size());
    curl_easy_setopt(curl_, CURLOPT_POSTFIELDS, json_data_.c_str());

    curl_easy_setopt(curl_, CURLOPT_USERAGENT, "chatfs/1.0");
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
