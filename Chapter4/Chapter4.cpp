#include <iostream>
#include <iomanip>


int main(){
    short choice;
    do{
        do{
            std::cout << "\nPrograms from Chapter 4";
            std::cout << "\n1. Minimum/Maximum.2 Roman Numeral Calculator\3. Magic Dates";
            std::cout << "\nSelection: ";
            std::cin >> choice;
            if(!isdigit(choice))
                std::cout << "\nONLY ENTER DIGITS PLEASE\n";
        }while(!isdigit(choice));

        std::cout << std::setprecision(2) << std::fixed;

        

    }while(choice != 25);
}