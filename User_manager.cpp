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
    //std::cout << "Reached here" << std::endl;
    if (in.is_open()){
        in >> j;
        this-> current_id = j.value("current_id", 0);
        //std::cout << "const f1 "<< std::endl;
    }
    else {
        //std::cout << " creating new file ";
        j["users"] = json::array(); 
        j["current_id"] = 0;
        this->current_id = 0;
        std::ofstream out(user_file);
        out << j.dump(4);
    }
    std::cout << "Reached here 22" << std::endl;
}
int User_manager::create_unique_id(){
    //mhm temp
    this-> current_id++;
    j["current_id"] = this->current_id;
    return current_id; 
}
//maybe search user should just search it not return it 
bool User_manager::search_user_name(const std::string &name){
    for(auto object: j["users"]){
        if (object["user_name"] == name) { 
            //std:: cout << object["user_name"] << object["id"] << object["db_file_name"];
            //std::cout << "found";
            return true;
        }
    }
    return false; 
}
//add a get_user 
bool User_manager::add_user(const std::string user_name){
    //well first you want to search it and make sure it does not exist 
    if (!search_user_name(user_name)){
        int id = create_unique_id(); 
        std::string file_name = user_name+"cdb.txt";
        User user1(user_name,id,file_name);
        j["users"].push_back(user1);
        return true;
    }
    //means it already exist or something else happened ....
    else return false;
}
User User_manager::get_user(const std::string name){
    User person1; 
    for(auto object: j["users"]){
        if (object["user_name"] == name) { 
            std::cout << " FOUND FF " << std::endl;
            person1.set_user_name(object["user_name"].get<std::string>()); 
            person1.set_user_id(object["id"].get<int>());
            person1.set_file(object["db_file_name"].get<std::string>());
        }
    }
    return person1;
};
void User_manager::close(){
     std::ofstream outfile(this->user_file);
     outfile << j.dump(4);
}
User_manager::~User_manager() {
    close(); 
}
