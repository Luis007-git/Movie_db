//using it to test out cdb class
#include "Cdb.h"
#include <iostream>
using namespace std;
int main() {
    Database db1("Movies.txt");
    // db1.add_movie("Tarzan",static_cast<float>(10));
    // db1.add_movie("Jurrasic Park",static_cast<float>(8.5));
    // db1.add_movie("Harry potter",static_cast<float>(8));
    // db1.add_movie("Jumanji",static_cast<float>(7));
    // db1.add_movie("Inception",static_cast<float>(9));
    // db1.add_movie("Blade Runner",static_cast<float>(8.5));
    // db1.display_by_rating(); 
    // cout << "after alpha: " << endl; 
    db1.add_movie("Toys Story 3",8.889898989888889898889);
    cout << "displaying vector: \n";
    db1.display_vec(); 
    cout << "displaying db: \n"; 
    db1.display_db(); 
    return 0; 
}