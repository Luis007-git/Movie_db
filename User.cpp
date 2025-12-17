#include "User.h"
#include <string>

//getters
const std::string& User::get_user_name()const{return this->user_name;};
const std::string& User::get_file_name()const{return this->file_name;};
int User::get_user_id()const{return this->user_id;};
//setters 
void User::set_user_name(const std::string& user){
    this->user_name = user;
}
void User::set_file(const std::string& file){
    this->file_name = file; 
}
void User::set_user_id(const int id){
    this->user_id = id; 
}