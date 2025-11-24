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
        std::string user_id;
        std::string user_name; 
        //user shouldnt really have the db just the db file name 
        std::string file_name; 
    public:
        User(std::string user_id, std::string user_name){
            //what db does it have find the db file inside the json file 
            //json get db file = db1(file_name)
        }
        //maybe later make sure the length is right and its just letters or however you need them 
        void change_username (std::string& new_name){
            user_name = new_name; 
        }


};



#endif