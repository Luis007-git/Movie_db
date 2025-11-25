#ifndef USER_H
#define USER_H
#include "json.hpp"
using json = nlohmann::json;
//#include "Cdb.h"
#include <string>

//user has name unique id
//has file name for their db and has a username 
// add pw later 
// you have a seperate file that has all the users by id user name and file name 
class User {
    private:
        int user_id;
        std::string user_name; 
        //user shouldnt really have the db just the db file name 
        std::string file_name; 
    public:

        //well when creating a user it goes to the user_manager if it finds it then good returns a user
        //if it does not find the user you can create a new one 
        User(std::string user_id, std::string user_name){
            //what db does it have find the db file inside the json file 
            //json get db file = db1(file_name)
        }
        //maybe later make sure the length is right and its just letters or however you need them 
        void change_username (std::string& new_name){
            user_name = new_name; 
        }
        //getters
        const std::string& get_user_name()const{return this->user_name;};
        const std::string& get_file_name()const{return this->file_name;};
        int get_user_id()const{return this->user_id;};
        //setters 
        void set_user_name(const std::string& user){
            this->user_name = user;
        }
        void set_file(const std::string& file){
            this->file_name = file; 
        }
        void set_user_id(const int id){
            this->user_name = id; 
        }
};



#endif