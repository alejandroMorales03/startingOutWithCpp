#include <iostream>
using namespace std;

struct MovieData
{
    string title;
    string director;
    int year_released;
    float running_time;
    float prod_costs;
    float first_year_rev;
};

void getMovieInfo(MovieData&);
void printData(MovieData&);

int main(){
    MovieData movies[2];
    
    for(short index = 0; index < 2; index++){
        cout << "\nFor Movie #" << (index + 1 );
        getMovieInfo(movies[index]);
        cin.ignore();
    }

    for(short index = 0; index < 2; index++)
        printData(movies[index]);
    cout << "\n";
}

void getMovieInfo(MovieData& movie){
    cout << "\n\nEnter title: ";
    getline(cin, movie.title);
    
    cout << "Enter the director: ";
    getline(cin, movie.director);

    cout << "Enter the year it was released: ";
    cin >> movie.year_released;

    cout << "Enter running time in minutes: ";
    cin >> movie.running_time;

    cout << "Enter production costs: ";
    cin >> movie.prod_costs;

    cout << "Enter first year revenues: ";
    cin >> movie.first_year_rev;

    movie.first_year_rev = movie.first_year_rev - movie.prod_costs;
}


void printData(MovieData& movie){
    cout << "\nTitle: " << movie.title;
    cout << "\nDirector: " << movie.director;
    cout << "\nRelease Year: " << movie.year_released;
    cout << "\nRunning Time (min): " << movie.running_time;

    if(movie.first_year_rev > 0)
        cout << "Profit: $ " << movie.first_year_rev;
    else    
        cout << "\nLoss: $ " << -movie.first_year_rev;

    cout << "\n";
}