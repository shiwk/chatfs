#include "chat_bot.hpp"
#include <iostream>
#include <nlohmann/json.hpp>

bool chatfs::chat::ChatBot::Send(const std::string& send_msg, std::string &recv_msg)
{
    GenerateHeaderAndPostData(send_msg);
    std::string resp;
    bool res = client_->Request(resp);
    assert(res);
    //std::cout << "recv_msg:" << recv_msg << std::endl;
    ParseResponse(resp, recv_msg);
    //std::cout << "content:" << recv_msg << std::endl;
    return true;
}

void chatfs::chat::ChatBot::GenerateHeaderAndPostData(const std::string& send_msg)
{
    auto config = nlohmann::json::parse(configBuf_.str());
    std::string url;
    config["url"].get_to<std::string>(url);
    client_->SetUrl(url);
    std::string sk;
    config["sk"].get_to<std::string>(sk);
    client_->AddHeader("Content-Type: application/json");
    client_->AddHeader("Authorization: Bearer " + sk);

    nlohmann::json json_data;
    json_data["model"] = config["model"];
    std::string model;
    json_data["model"].get_to<std::string>(model);
    json_data["messages"] = nlohmann::json::array();
    
    nlohmann::json message;
    message["role"] = config["role"];
    message["content"] = send_msg;
    json_data["messages"].push_back(message);
    json_data["temperature"] = config["temperature"];
    client_->SetJsonData(json_data.dump());
    
}

void chatfs::chat::ChatBot::ParseResponse(const std::string &resp, std::string &data)
{
    auto respJson = nlohmann::json::parse(resp);
    respJson["choices"][0]["message"]["content"].get_to<std::string>(data);
}

chatfs::chat::Chating *chatfs::chat::Chating::NewChat()
{
    return new ChatBot(std::make_shared<ChatClient>());
}
