#include <iostream>
#include <iomanip>

int main(){
    char choice;
    do{
        std::cout << "\nPROGRAMS FROM CHAPTER 3";
        std::cout << "\nA. Miles Per Gallon\nB. Stadium Seating\nC. Test Average";
        std::cout <<"\nD. Average Rainfall\nE. Male and Female Percentages\nF. Ingredient Adjuster";
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
            case 'D':{
                std::string months[3];
                float rainfall[3];
                float average = 0;

                std::cout << "\nEnter 3 months followed by the amount in rain (in inches) for each month:\n";
                for(short index = 0; index < 3; index++){
                    std::cout << "\nMonth: ";
                    std::cin.ignore();
                    getline(std::cin, months[index]);
                    std::cout << "Rain in inches: ";
                    std::cin >> rainfall[index];
                    average += rainfall[index];
                }

                average /= 3;

                std::cout << "\nThe average rainfall for " << months[0] << ", ";
                std::cout << months[1] << ", " << "and " << months[2] << " was ";
                std::cout << average;     
                break;           
            }
            case 'E':{
                int males, females;
                float fem_avg, male_avg;
                std::cout << "\nEnter the number of males registered in the class: ";
                std::cin >> males;
                std::cout << "\nEnter the number of females registered in the class: ";
                std::cin >> females;

                fem_avg = static_cast<float>(females) / (males + females) * 100;
                male_avg = static_cast<float>(males) / (males + females) * 100;
                
                std::setprecision(5);
                std::cout << "\nAverage Male Enrollment: " << std::setw(7) << male_avg;
                std::cout << "\nAverage Female Enrollment: " << std::setw(5) << fem_avg;
                break;
            }
            case 'F':{
                const float SUGAR_CUP = 1.5, BUTTER_CUP = 1, FLOUR_CUP = 2.75;
                const short COOKIES = 48;

                float sugar, butter, flour, cookies_to_COOKIES_rate;
                short cookies;

                std::cout << "\nHow many cookies would you like to make: ";
                std::cin >> cookies;
                cookies_to_COOKIES_rate = static_cast<float>(cookies) / COOKIES;
                
                sugar = SUGAR_CUP * cookies_to_COOKIES_rate;
                butter = BUTTER_CUP * cookies_to_COOKIES_rate;
                flour = FLOUR_CUP * cookies_to_COOKIES_rate;

                std::cout << "\nNeeded Ingredients";
                std::cout << "\n\nSugar: " << std::setw(6) << sugar << " cups";
                std::cout << "\nButter: " << std::setw(5) << butter << " cups";
                std::cout << "\nFlour: " << std::setw(6) << flour << " cups";
                break;

            }
            case 'G':{
                
            }
            default:{
                std::cout << "\nINVALID INPUT";
                break;
            }
        }
        std::cout << "\n";

        
    }while(choice < 'A'|| choice > 'Y');

}