#ifndef CDB_H
#define CDB_H

#include <vector> 
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
//made stuff const where applicable and passed by ref 
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
        void load_from_file();//populated the vector with movies
        void add_file(const string& file_name); //adds a file to the database and then it should run ->load  from file 
        void display_vec(); //displays contents inside the vec
        int movie_search(const string& movie); //searches for a specific movie and returns the rating
        bool is_file_empty();//just checks to see if our file is empty
        void display_db();//shows everything in our database thats going to be added is in display_vec this would show the old file before you ran it 
        //it was the old way to populate a vector will be deleted 
        //void populate_vec();//fills in the vector with the items in database
        bool add_movie(const string& name, float rating); //adds a new movie to the DB bool return because you want to have a way to tell the people if the movie was added or not without cout
        //prob have to move the content to a diff member function doesnt make sense to have it here
        void display_in_alpha(); //sorts vector  by movie name A-Z
        void display_by_rating();//sorts vector by rating 10-0;
        //working here
        void delete_movie(const string& movie_name);//find the movie by name and then deletes it because your usign a vector deleting a movie is gonna be consuming 
        void fast_delete(const string& movie_name);
        void save_to_file();
        ~Database() {
        save_to_file();   // automatically called when object is destroyed
        }
        
};









#endif
