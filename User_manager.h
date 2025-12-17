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
        int current_id; 
        int create_unique_id(); 
    public:
        User_manager(std::string file);
        //add a get user
        //well i guesss it will return the users file_name if it exist 
        // returns a user if found if not calls add_user func
        bool search_user_name(const std::string &name);
        //creates user and adds a file for it true if added false if not
        bool add_user(const std::string user_name);
        User get_user(const std::string user_name);
        void close();
       ~User_manager(); 
};



#endif