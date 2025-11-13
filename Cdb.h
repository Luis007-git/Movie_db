#ifndef CDB_H
#define CDB_H
#include <iostream>
#include <vector> 
#include <fstream> 
#include <sstream> 
#include <algorithm> 
using namespace std;
/*
Luis Aguilar
File name: Cdb.h
03/10/2022
Problem: Creating a database for movies. Storing the information in a seperate file.
Using a vector as a way to sort out the movies or to organize them in whatever way. WIll need user interface after this
*/
//****Not done still working on it. Its just the latest I've been doing*****
//needs backup copy db file in case you lose data // still needs to be added
//edited nov 25 added test files for cdb and interface
int search(string word,char c);
class Database {
    private: 
        //created the datatype movie which consist of name and rating of the movie
        struct Movie{
            string name; 
            float rating; 
        };
        //less than struct is used for custom sort. Where string sorts by string in alphabetic order and
        //rating sorts by movie rating where the higher ratings get placed at the begining of vec
        struct compare_by_name
        {
            inline bool operator()(const Movie&m1, const Movie&m2){
                return (m1.name< m2.name);
            }
        };
        struct compare_by_rating{
            inline bool operator() (const Movie&m1, const Movie&m2){
                return(m1.rating > m2.rating);
            }
        };
        //my Db  has a vector of movies to help manipulate the data
        vector<Movie>items;
        //redundant not needed info is already in items.size() 
        //int number_of_items;
        string file_name;
    public:
        Database():file_name(""){}
        //if you have a file name then populate the vector 
        Database(const std::string& file_name) :items(),file_name(file_name) {
            load_from_file();
        };
        void load_from_file();
        void add_file(string file_name);
        void display_vec(); //displays contents inside the vec
        int v_search(string movie); //searches for a specific movie and returns the rating
        bool is_file_empty();//just checks to see if our file is empty
        void display_db();//shows everything in our database
        void populate_vec();//fills in the vector with the items in database
        void add_movie(string name, float rating); //adds a new movie to the DB
        //prob have to move the content to a diff member function doesnt make sense to have it here
        void display_in_alpha(); //sorts vector  by movie name A-Z
        void display_by_rating();//sorts vector by rating 10-0;
        //working here
        void delete_movie(string movie_name);//find the movie by name and then deletes it
        void save_to_file();
        ~Database() {
        save_to_file();   // automatically called when object is destroyed
        }
        
};









// void Database::add_file(string file_name){
//     this->file_name = file_name;
// }
// //time Complexity O(n)
// int Database::v_search(string movie){ // searches for movie and returns its index in vec
//     for(int i = 0; i < items.size(); i++){
//         if(items[i].name == movie){
//             return i; 
//         }
//     }
//     return -1; // if it doesnt find anything
// }
// bool Database::is_file_empty(){
//     ifstream myfile(file_name); 
//     return myfile.peek() == ifstream::traits_type::eof();
// }
// //goes line by line displayign time complexity O(n)
// void Database::display_db(){ //output everything in the file
//     string line;
//     ifstream myfile(file_name); 
//     int counter = 0; 
//     if (myfile.is_open()){
//         while(getline(myfile,line)){ 
//             cout << line << endl; 
//             counter++; 
//         }
//     }
//     if(counter == 0){ //counter will be zero when file is empty
//         cout << "FILE IS EMPTY" << endl;
//     }
//     myfile.close(); 
// }
// //goes line by line on vector and outputs results to screen 
// //not really meant for the user
// //time complexity O(n)
// void Database::display_vec(){
//     for(int i = 0; i < items.size();i++){
//         cout << items[i].name << " " ;
//         cout  << items[i].rating << endl; 
//     }
// }
// //needs cleaning up
// //populates the vector of movies
// void Database::populate_vec(){ 
//     // if(!this->is_file_empty()){
//     //     ifstream myfile(file_name);
//     //     m ss;   
//     // }
//     ifstream myfile(file_name);
//     Movie m1; 
//     string words; //the whole line
//     string m_name; // movie name
//     stringstream ss; 
//     int rating_pos;
//     float rating; 
//     if(myfile.is_open()){
//         while(getline(myfile,words)){
//             rating_pos = search(words,'#'); //to find the pos of this char that starts rating for movies

//             m_name = words.substr(rating_pos+1, words.size());
//             ss << m_name; //convert m_name to an int and give the value to rating
//             ss >>  rating; 
//             m_name = words.substr(6,rating_pos-15);
//             m1.rating = rating;
//             m1.name = m_name; 
//             items.push_back(m1);
//             ss.clear(); //flushes out ss
//         }
//     }
//     myfile.close(); 
// }
// void Database::add_movie(string name, float rating){
//     if(rating > 10 or rating < 0){
//         cout << "Rating is too high or too low" << endl << "Movie NOT added " << endl; 
//         cout << "Acceptable ratings-> 1-10 float\n";
//         return; //gets out of method without doing anything
//     }
//     ofstream myfile;
//     myfile.open(file_name, ios::app);
//     myfile << "Name: " << name << " Rating: #" << rating  << "\n";
//     Movie m1;
//     m1.name = name; 
//     m1.rating = rating;
//     if(!items.empty()){ // only do it if vec isnt empty
//         items.push_back(m1);
//     }
//     cout << name << " was added to db " << endl;
//     myfile.close();
// }
// //uses std sort time complexity O(nlogn)
// void Database::display_in_alpha(){ // have to parse out the text to strings and ints
//     if(items.empty()){ //if vector is empty
//         this->populate_vec(); 
//     }
//     sort(items.begin(), items.end(), less_than_key_string());// can also overload '<' operator
// }
// //same as alpha. Time complexity: O(nlogn)
// void Database::display_by_rating(){ //default highest to lowest
//     if(items.empty()){
//         this->populate_vec(); 
//     }
//     sort(items.begin(), items.end(), less_than_key_rating());
// }
// void Database::delete_movie(string movie_name){
//     int pos = 0; 
//     if(!items.empty()){ // deletes it from vec first 
//             pos = v_search(movie_name);
//             items.erase(items.begin()+pos);
//     }

// }
// //helper function used in populate vec 
// //finds any given char in a string  and returns its position in string 0-Intmax
// //if not found return -1
// int search(string word,char c){
//     int pos =0; 
//     int i = word.size()-1;
//     while (i > 0 ){
//         if(word[i] == c){
//             return i; 
//         }
//         else{
//             --i;
//         }
//     }
//     return -1; // if not found
// }

#endif
