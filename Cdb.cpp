#include "Cdb.h"
#include <fstream> 
#include <sstream> 
#include <algorithm> 
#include <iostream> 
#include <vector>
#include <string>
//can delete the name space later 
using namespace std;
int search(const string& word,char c);

//adds file values into the items vector seperates the string from ints using the ',' as a parser
void Database::load_from_file(){
    if(this->file_name.empty()){
        return;
    }
    std::ifstream file(file_name);
    if(!file){
        return;
    }
    //movie struct needs name and rating
    std::string movie_name;
    float movie_rating; 
    while (file >> std::ws && std::getline(file, movie_name, ',') && file >> movie_rating) {
            items.push_back(Database::Movie{movie_name, movie_rating});
    }
}
//time Complexity O(n) //returns index to the movie iif it exists -1 if not
int Database::movie_search(const string& movie){ // searches for movie and returns its index in vec
    for(int i = 0; i < items.size(); i++){
        if(items[i].name == movie){
            return i; 
        }
    }
    return -1; // if it doesnt find anything
}
bool Database::is_file_empty(){
    ifstream myfile(file_name);
    //well this is tricky so because file doesnt get uploaded till the object dies maybe if they check if file is empty populate it first 
    this->save_to_file();  
    return myfile.peek() == ifstream::traits_type::eof();
}

//goes line by line displayign time complexity O(n)
//display db is actually display file for debug purposes 
void Database::display_db(){ //output everything in the file
    string line;
    ifstream myfile(file_name); 
    int counter = 0; 
    if (myfile.is_open()){
        while(getline(myfile,line)){ 
            cout << line << endl; 
            counter++; 
        }
    }
    if(counter == 0){ //counter will be zero when file is empty
        cout << "FILE IS EMPTY" << endl;
    }
    myfile.close(); 
}

//goes line by line on vector and outputs results to screen 
//not really meant for the user
//time complexity O(n)
void Database::display_vec(){
    for(int i = 0; i < items.size();i++){
        cout << items[i].name << ", " << items[i].rating << endl; 
    }
}

bool Database::add_movie(const string& name, float rating){
    //make sure it doesnt have doubles dont add if it already exist 
    if(rating > 10 || rating < 0){
        // let user handle however they want 
        // cout << "Rating is too high or too low" << endl << "Movie NOT added " << endl; 
        // cout << "Acceptable ratings-> 0-10 float\n";
        // if you want better return types implement enum return type
         return false; 
    }
    //maybe have to stacks one that can have the db out of order and the other in order?
    // time complexity to check if this name is already in db is n can be expesnive to keep adding if you have to check everytime 
    if(movie_search(name) >= 0){
        return false; 
    }

    Movie m1(name,rating);
    items.push_back(m1);
    //aka added 
    return true; 
}
//uses std sort time complexity O(nlogn)
void Database::sort_in_alpha(){ // have to parse out the text to strings and ints
    sort(items.begin(), items.end(), [](const Database::Movie& m1,const Database::Movie& m2 ){
        return m1.name < m2.name;
    });// can also overload '<' operator
}
//same as alpha. Time complexity: O(nlogn) uses stl sort 
void Database::sort_by_rating(){ //default highest to lowest
    sort(items.begin(), items.end(), [](const Database::Movie& m1,const Database::Movie& m2 ){
        return m1.rating > m2.rating;
    });
}

//time complexity is O(n) steps n+n+c
bool Database::delete_movie(const string& movie_name){
    int index = movie_search(movie_name);
    if(index < 0){
        //bad practice to cout ;( using bool
        //cout << "cand delet it does not exist ";
        return false; 
    } 
    //two ways to delete if you care about order or if you dont if you dont its faster 
    items.erase(items.begin() + index);
    return true;
}

//time complexity for this deletions is n beceause of movie search steps n+c+c
bool Database::fast_delete(const string& movie_name){
    int index = movie_search(movie_name);
    if(index < 0){
        // return false instead 
        //cout << "cand delet it does not exist ";
        return false; 
    } 
    items[index] = items.back();  
    items.pop_back(); 
    return true; 
}

//called when program ends and it populates the file with the things in the items list 
//saves time better than adding one at a time if user keeps adding movies to db
void Database::save_to_file(){
    ofstream my_file(file_name, ios::trunc);
    if (!my_file) {
        cout << "Error: Could not open file " << file_name << endl;
        return;
    }
    for(const auto& movie: items){
        my_file << movie.name << ", " << movie.rating << endl;
    }
}
//return vec 
const vector<Database::Movie>& Database::get_items()const{
    return items; 
}
//return file name 
string Database::get_file_name()const{
    return this->file_name; 
}
//helper function used in populate vec 
//finds any given char in a string  and returns its position int string 0-Intmax
//if not found return -1
int search(const string& word,char c){
    //int pos =0; 
    int i = word.size()-1;
    while (i > 0 ){
        if(word[i] == c){
            return i; 
        }
        else{
            --i;
        }
    }
    return -1; // if not found
}







//needs cleaning up
//populates the vector of movies
//old way to populate vec 
//not needed anymore 
// void Database::populate_vec(){ 
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
//adds a movie to the items vec and into the file