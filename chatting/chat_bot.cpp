#include "chat_bot.hpp"
#include <iostream>
#include <nlohmann/json.hpp>

bool chatfs::chat::ChatBot::Send(const std::string send_msg, std::string &recv_msg)
{
    auto config = nlohmann::json::parse(buffer_.str());
    std::string url;
    config["url"].get_to<std::string>(url);

    std::string sk;
    config["sk"].get_to<std::string>(sk);

    client_->SetUrl(url);
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
    bool res = client_->Request(recv_msg);
    assert(res);
    std::cout << "recv_msg:" << recv_msg << std::endl;
    return true;
}

chatfs::chat::Chating *chatfs::chat::Chating::NewChat()
{
    return new ChatBot(std::make_shared<ChatClient>());
}
