#ifndef CDB_H
#define CDB_H

#include <vector> 
#include <cmath>
#include<string>
#include<vector>
//dont use namespace std' bad practice in the h file
//using namespace std;
/*
Luis Aguilar
File name: Cdb.h
created:03/10/2022
Edited:
11/24/2025
Problem: Creating a database for movies. Storing the information in a seperate file.
Using a vector as a way to sort out the movies or to organize them in whatever way. Main purpose learning C++ classes and data strucures 
*/
//****Not done still working on it. Its just the latest I've been doing*****
//needs backup copy db file in case you lose data // still needs to be added
//edited nov 25 added test files for cdb and interface
//made stuff const where applicable and passed by ref 
//next going to add review part 



//int search(std::string word,char c);
class Database {
    public: 
               //created the datatype movie which consist of name and rating of the movie
        struct Movie{
            std::string name; 
            float rating; 
            // the rounding is not really needed in here we can just add that when we take user input
            Movie(const std::string& n, float r): name(n), rating(std::roundf(r * 10.0f) / 10.0f) {}
        };

    private: 
        //my Db  has a vector of movies to help manipulate the data
        std::vector<Movie>items;
        //redundant not needed info is already in items.size() 
        //int number_of_items;
        std::string file_name;
    public:
        Database():file_name(""){}
        //if you have a file name then populate the vector 
        Database(const std::string& file_name) :items(),file_name(file_name) {
            load_from_file();
        };
        void load_from_file();//populated the vector with movies
        void display_vec(); //displays contents inside the vec
        int movie_search(const std::string& movie); //searches for a specific movie and returns the rating
        bool is_file_empty();//just checks to see if our file is empty
        void display_db();//shows everything in our database thats going to be added is in display_vec this would show the old file before you ran it 
        //it was the old way to populate a vector will be deleted 
        //void populate_vec();//fills in the vector with the items in database
        bool add_movie(const std::string& name, float rating); //adds a new movie to the DB bool return because you want to have a way to tell the people if the movie was added or not without cout
        //prob have to move the content to a diff member function doesnt make sense to have it here
        void sort_in_alpha(); //sorts vector  by movie name A-Z
        void sort_by_rating();//sorts vector by rating 10-0;
        //working here
        bool delete_movie(const std::string& movie_name);//find the movie by name and then deletes it because your usign a vector deleting a movie is gonna be consuming 
        bool fast_delete(const std::string& movie_name);//implamented for fun not rly needed. 
        void save_to_file();
        //setters
        void add_file(const std::string& file_name); //adds a file to the database and then it should run ->load  from file 
        //getter functions
        const std::vector<Movie>& get_items()const; 
        std::string get_file_name()const; 
        ~Database() {
        save_to_file();   // automatically called when object is destroyed
        }
        
};









#endif
