#include <iostream>
#include <iomanip>

int main(){
    char choice;
    do{
        std::cout << "\nPROGRAMS FROM CHAPTER 3";
        std::cout << "\nA. Miles Per Gallon\nB. Stadium Seating\nC. Test Average";
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
            case 'B':{
                
                char ticket;
                double ticket_price, income = 0;
                int quantity;
                do{
                    do{
                        std::cout << "\nTicket Prices\n\nClass A: $ 15.00\tClass B: $ 12.00\nClass C: $  9.00\n";
                        std::cout << "\nEnter D to finish buying\n";
                        std::cout << "\nWhich ticket class would you like: ";
                        std::cin.ignore();
                        std::cin.get(ticket);
                        switch(ticket){
                            case 'A': 
                                ticket_price = 15.00;
                                break;
                            case 'B': 
                                ticket_price = 12.00;
                                break;
                            case 'C':
                                ticket_price = 9.00;
                                break;
                            case 'D':
                                std::cout << "\nSHUTTING DOWN\n";
                                break;
                            default:
                                std::cout << "\nINVALID INPUT\n";
                                break;
                        }
                    }while(ticket < 'A' || ticket > 'D' );
                    
                    if(ticket != 'D'){
                        std::cout << "Enter number of tickets of selected class: ";
                        std::cin >> quantity;
                        income += quantity * ticket_price;
                    }   

                }while(ticket != 'D');
                std::cout << "\nTotal Sales: " << std::showpoint << std::setprecision(2) << std::fixed << income;
                break;
            }
            case 'C':{
                float scores[5];
                float sum, average;
                
                std::cout << "\n";
                
                for(short index = 0; index < (sizeof(scores) / sizeof(scores[0])); index++){
                    std::cout << "Enter score # " << (index + 1) << ": ";
                    std::cin >> scores[index];
                    sum += scores[index];
                }

                average = sum / (sizeof(scores) / sizeof(scores[0]));
                std::cout << "\nAverage: " << std::showpoint << std::setprecision(1) << std::fixed << average;
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