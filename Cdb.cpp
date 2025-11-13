#include "Cdb.h"
int search(string word,char c);

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
            items.push_back({movie_name, movie_rating});
    }
}
//time Complexity O(n)
int Database::v_search(string movie){ // searches for movie and returns its index in vec
    for(int i = 0; i < items.size(); i++){
        if(items[i].name == movie){
            return i; 
        }
    }
    return -1; // if it doesnt find anything
}
bool Database::is_file_empty(){
    ifstream myfile(file_name); 
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
//needs cleaning up
//populates the vector of movies
//old way to populate vec 
void Database::populate_vec(){ 
    // if(!this->is_file_empty()){
    //     ifstream myfile(file_name);
    //     m ss;   
    // }
    ifstream myfile(file_name);
    Movie m1; 
    string words; //the whole line
    string m_name; // movie name
    stringstream ss; 
    int rating_pos;
    float rating; 
    if(myfile.is_open()){
        while(getline(myfile,words)){
            rating_pos = search(words,'#'); //to find the pos of this char that starts rating for movies

            m_name = words.substr(rating_pos+1, words.size());
            ss << m_name; //convert m_name to an int and give the value to rating
            ss >>  rating; 
            m_name = words.substr(6,rating_pos-15);
            m1.rating = rating;
            m1.name = m_name; 
            items.push_back(m1);
            ss.clear(); //flushes out ss
        }
    }
    myfile.close(); 
}
//adds a movie to the items vec and into the file
void Database::add_movie(string name, float rating){
    if(rating > 10 || rating < 0){
        cout << "Rating is too high or too low" << endl << "Movie NOT added " << endl; 
        cout << "Acceptable ratings-> 0-10 float\n";
        return; //gets out of method without doing anything
    }
    // ofstream myfile;
    // myfile.open(file_name, ios::app);
    // if (!myfile) {
    //     cout << "Error: Could not open file " << file_name << endl;
    //     return;
    // }
    // myfile << name << ", " << rating  << "\n";
    Movie m1;
    m1.name = name; 
    m1.rating = rating;
    items.push_back(m1);
    cout << name << " was added to db with rating of: " << m1.rating << endl;
}
//uses std sort time complexity O(nlogn)
void Database::display_in_alpha(){ // have to parse out the text to strings and ints
    if(items.empty()){ //if vector is empty
        this->populate_vec(); 
    }
    sort(items.begin(), items.end(), compare_by_name());// can also overload '<' operator
}
//same as alpha. Time complexity: O(nlogn)
void Database::display_by_rating(){ //default highest to lowest
    if(items.empty()){
        this->populate_vec(); 
    }
    sort(items.begin(), items.end(), compare_by_rating());
}
void Database::delete_movie(string movie_name){
    int pos = 0; 
    if(!items.empty()){ // deletes it from vec first 
            pos = v_search(movie_name);
            items.erase(items.begin()+pos);
    }

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
//helper function used in populate vec 
//finds any given char in a string  and returns its position int string 0-Intmax
//if not found return -1
int search(string word,char c){
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
