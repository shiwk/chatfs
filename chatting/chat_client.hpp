#ifndef CLIENT_CURL_HPP
#define CLIENT_CURL_HPP

#include <curl/curl.h>
#include <string>

namespace chatfs
{

    class ChatClient
    {
    public:
        // ChatClient();
        // ~ChatClient()
        // bool Post(const std::string &url, const std::string &data, std::string &response);
        // bool Get(const std::string &url, std::string &response);
        ChatClient()
        {
            curl_global_init(CURL_GLOBAL_ALL);
            curl_ = curl_easy_init();
        }

        ~ChatClient()
        {
            curl_easy_cleanup(curl_);
        }

        bool Post(const std::string &url, const std::string &data, std::string &response)
        {
            if (!curl_)
            {
                return false;
            }

            curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl_, CURLOPT_POST, 1L);
            curl_easy_setopt(curl_, CURLOPT_POSTFIELDS, data.c_str());
            // curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, &WriteCallback);
            curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &response);

            CURLcode res = curl_easy_perform(curl_);
            return (res == CURLE_OK);
        }

        bool Get(const std::string &url, std::string &response)
        {
            if (!curl_)
            {
                return false;
            }

            curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
            // curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, &WriteCallback);
            curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &response);

            CURLcode res = curl_easy_perform(curl_);
            return (res == CURLE_OK);
        }

    private:
        CURL *curl_ = nullptr;

        // static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
        // {
        //     size_t realsize = size * nmemb;
        //     std::string *str = static_cast<std::string *>(userp);
        //     str->append(static_cast<char *>(contents), realsize);
        //     return realsize;
        // }
    };

}

#endif