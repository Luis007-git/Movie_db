#pragma once
#include "User.h"
#include "json.hpp"

using nlohmann::json;

// Convert User → JSON // used in a push_back call 
inline void to_json(json& j, const User& u) {
    j = json{
        {"user_name", u.get_user_name()},
        {"id", u.get_user_id()},
        {"db_file_name", u.get_file_name()}
    };
}

// Convert JSON → User
//fix later 
inline void from_json(const json& j, User& u) {
    u.set_user_name(j.at("user_name").get<std::string>());
    u.set_user_id(j.at("id").get<int>());
    u.set_file(j.at("db_file_name").get<std::string>());
}
