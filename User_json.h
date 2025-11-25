#pragma once
#include "User.h"
#include "json.hpp"

using nlohmann::json;

// Convert User → JSON
inline void to_json(json& j, const User& u) {
    j = json{
        {"username", u.get_user_name()},
        {"id", u.get_user_id()},
        {"db_file_name", u.get_file_name()}
    };
}

// Convert JSON → User
//fix later 
void from_json(const json& j, User& u) {
    u.set_user_name(j.at("username").get<std::string>());
    u.set_user_id(j.at("id").get<int>());
    u.set_file(j.at("db_file_name").get<std::string>());
}
