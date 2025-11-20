#ifndef USER_H
#define USER_H
#include "json.hpp"
using json = nlohmann::json;
#include "Cdb.h"
#include <string>

//user has name unique id
class User {
    private:
        std::string user_id;
        std::string user_name; 
        Database db1; 
    public:
        User(std::string user_id, std::string user_name){}
        //maybe later make sure the length is right and its just letters or however you need them 
        void change_user_name (std::string& new_name){
            user_name = new_name; 
        }

};



#endif