#include "json.hpp"
#include "User.h"
#include "User_manager.h"
#include "User_json.h"
#include <iostream> 
using json = nlohmann::json;
#include <fstream>
//#include "Cdb.h"
#include <string>
//open file and initizialize the json object 
User_manager::User_manager(std::string file_name) : user_file(file_name){
    std::ifstream in(user_file);
    //if j file exist read it into j
    //else create one
    std::cout << "Reached here" << std::endl;
    if (in.is_open()){
        in >> j;
    }
    else {
        j["users"] = json::array(); 
        std::ofstream out(user_file);
        out << j.dump(4);
    }
    std::cout << "Reached here 22" << std::endl;
}
User* User_manager::search_user_name(const std::string &name){
    
}