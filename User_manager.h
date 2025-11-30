#ifndef USER_MANAGER
#define USER_MANAGER
#include "json.hpp"
#include "User.h"
using json = nlohmann::json;
//#include "Cdb.h"
#include <string>

//user has name unique id
//has file name for their db and has a username 
// add pw later 
// you have a seperate file that has all the users by id user name and file name 
class User_manager {
    private:
        std::string user_file; 
        json j; 
        int create_unique_id(); 
    public:
        User_manager(std::string file);
        //well i guesss it will return the users file_name if it exist 
        // returns a user if found if not calls add_user func
        User* search_user_name(const std::string &name);
        //creates user and adds a file for it 
        void add_user(const std::string user_name);
};



#endif