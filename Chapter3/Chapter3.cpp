#include <iostream>
#include <iomanip>

int main(){
    char choice;
    do{
        std::cout << "\nPROGRAMS FROM CHAPTER 3";
        std::cout << "\n A. Miles Per Gallon\n B. Stadium Seating";
        std::cout << "\n\nSELECTION: ";
        std::cin.get(choice);

        std::cout << std::setprecision(2) << std::fixed;
        switch (choice){
            case 'A':{
                int gallons;
                double miles, MPG;
                std::cout << "\nEnter gallons on full tank: ";
                std::cin >> gallons;
                std::cout << "\nEnter miles you can drive on full tank: ";
                std::cin >> miles;
                MPG = miles / gallons;
                std::cout << "\nMPG: " << std::setw(7) << MPG;
                break;
            }
            default:{
                std::cout << "\nINVALID INPUT";
                break;
            }
        }
        std::cout << "\n";

        
    }while(choice < 'A'|| choice > 'Y');

}