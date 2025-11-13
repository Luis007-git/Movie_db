#ifndef Interface_H
#define Interface_H
#include "Cdb.h"
#include <iostream>
#include <sstream>
using namespace std;
//every db needs a userinterface
class User_Interface{
    private:
        string file_name;
        Database db1; 
    public:
    // const dont display or get inputs bad practiced fixed nov12
        User_Interface(){
            string db_name; 
            cout << "Enter the name of the Databse: " << endl;
            cin >> db_name; 
            file_name = db_name; 
            Database db1(db_name);
        }
        User_Interface(string db_name){
            cout << "The name of your database file is  " << db_name<< endl;
            file_name = db_name; 
            db1.add_file(file_name);
        }
        void prompts(); // displays all the options you have
};
//switch to enum 
void User_Interface::prompts(){
    int input = 0; 
    string movie_name ="";
    float movie_rating = 0; 
    string string_rating; 
    stringstream ss; 
    // should probably transfter this to a string and just output string
    // so it can be used more than once
    cout  << "******************************************************************" << endl 
                << "\tHit enter after every prompt" << endl 
                <<"\tTo view DB press 1 " << endl 
                << "\tTo add to Db press 2 " << endl
                << "\tTo display in alplhabetic order 3" << endl
                << "\tTo sort by rating highest to lowest press 4"<< endl
            << "******************************************************************" << endl;
    cin >> input; 
    cin.ignore(); //clears input stream
    while(input != 9){
        switch(input) {
            case 1: 
                db1.display_db(); 
                break;
            case 2: 
                // adds a movie
                cout << "Enter movie name: ";
                // add are you sure you want to add this movie prompt
                getline(cin,movie_name);
                cout << "\nEnter movie rating(1-10): ";
                getline(cin,string_rating);
                ss <<string_rating;
                ss >> movie_rating; 
                cout << "THIS IS THE MOVIE RATING " << movie_rating << endl; 
                ss.clear();
                db1.add_movie(movie_name,movie_rating); 
                break;
            case 3: 
                db1.display_in_alpha();
                db1.display_vec(); 
                break;
            case 4:
                db1.display_by_rating(); 
                db1.display_vec(); 
                break;
            case 8: 
                cout  << "******************************************************************" << endl 
                    << "\thit enter after every prompt" << endl 
                    <<"\tTo view DB press 1 " << endl 
                    << "\tTo add to Db press 2 " << endl
                    << "\tTo display in alplhabetic order 3 " << endl
                    << "\tTo sort by rating highest to lowest press 4"<< endl
                << "******************************************************************" << endl;
                break;

            default:
                cout <<  "Enter a valid command to view command again press: 8 "<< endl; 
                break;
        }
        cout << "Enter 9 to exit or keep going or 8  to prompts again " << endl; 
        cin >> input; 
        cin.ignore(); 
    }
/// add delte movie 
    
}
#endif