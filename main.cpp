#include "User_manager.h"
#include "User.h"
#include <iostream> 
int main() {
    User_manager users1("All_User.json");
    users1.add_user("Amy01");
    users1.add_user("Luis01");
    users1.add_user("Anahi01");
    // User luis; 
    // luis = users1.get_user("Luis01");
    // std::cout << "Luis file name " << luis.get_file_name() << "Luis user_id " << luis.get_user_id() << "Luis user name  " << luis.get_user_name() << std::endl; 
    
}