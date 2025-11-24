//using it to test out cdb class
#include "Cdb.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
void test_default_constructor(){
    Database d1; 
    assert(d1.get_file_name() == "");
    assert(d1.get_items().empty());
    cout << "passed default constructor\n";

}
void test_param_const(){
    Database d1("Movies.txt");
    assert(d1.get_file_name() == "Movies.txt");
    cout << "worked\nc";

}
void file_check(){
    Database d1("Movies.txt");
    d1.add_movie("Tarzan",9);
    assert(!d1.is_file_empty());
    cout << "passed file_check\n";
}
void test_sort(){
    //
}
void test_search(){
    Database d1("Movies.txt");
    d1.add_movie("Tarzan",9.2);
    assert(d1.movie_search("Tarzan")>=0); 
    d1.display_vec(); 
    d1.delete_movie("Tarzan");
    //assert(d1.get_items.empty()->empty);
    cout << "Search works and delete work\n"; 
}
void test_add_movie(){
    Database d2("Movies.txt");
    assert(d2.add_movie("Tarzan",-12) == false);
    assert(d2.add_movie("Tarzan",7) == true);
    assert(d2.add_movie("Tarzan",1) == false);
    assert(d2.add_movie("Bad Rating",11) == false);
    d2.delete_movie("Tarzan");
    assert(d2.add_movie("Tarzan",10) == true);
    cout << "Add works tests passed \n";
}
void test_sort_alpha(){
    Database d1("Movies.txt");
    d1.add_movie("Snow White",7);
    d1.add_movie("Shrek",9);
    d1.add_movie("Mulan",8);
    d1.add_movie("Jurasic Park", 8);
    d1.add_movie("Toy Story",8.5);
    d1.add_movie("Toy Story 3", 7);
    d1.add_movie("Mean Girls",9.2);
    d1.add_movie("Alpha",5);
    cout << " By alpha \n";
    d1.sort_in_alpha();
    d1.display_vec();
    cout << "By rating\n";
    d1.sort_by_rating(); 
    d1.display_vec(); 
}
int main() {
    cout << "running class test\n"; 
    test_sort_alpha(); 
    cout << "all test passed\n";
    return 0; 
}