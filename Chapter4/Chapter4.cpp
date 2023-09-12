#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>


int main(){
    short choice;
    do{
        std::cout << "\nPrograms from Chapter 4\n";
        std::cout << "\n 1. Minimum/Maximum\n 2. Roman Numeral Calculator\n 3. Magic Dates";
        std::cout << "\n 4. Areas of Rectangles\n 5. Body Mass Index\n 6. Mass and Weight";
        std::cout << "\n 7. Time Calculator \n 8. Color Mixer \n 9. Change for a Dollar Game";
        std::cout << "\n10. Days in a Month \n11. Math Totor\n12. Software Sales";
        std::cout << "\n13. Book Club Points\n14. Bank Charges";
        std::cout << "\n\nSelection: ";
        std::cin >> choice;

        std::cout << std::setprecision(2) << std::fixed << std::showpoint;
        
        switch(choice){
            case  1:{
                float fval, sval;
                std::cout << "\nEnter two numbers separated by a space: ";
                std::cin >> fval >> sval;  
                std::cout << "\n" << (fval > sval? fval : sval) << " is the largest";
                std::cout << "\n" << (fval < sval? fval : sval) << " is the smallest";
                break;
            }
            case  2:{
                short digit;
                bool valid_input = true;
                std::string numeral = "";
                std::cout << "\nEnter number from 1 to 10: ";
                std::cin >> digit;

                switch(digit){
                    case  4:{
                        numeral = "IV"; 
                        break;
                    }
                    case  9:{
                        numeral = "IX";
                        break;
                    }
                    case 10:{
                        numeral = "X";
                        break;
                    }    
                    case 5:
                    case 6:
                    case 7:
                    case 8:{
                        numeral =+ "V";
                        digit -= 5;
                    }
                    case 1:
                    case 2:
                    case 3:{
                        for(short ind = 0; ind < digit; ind++){
                            numeral += "I";
                        }
                        break;  
                    }  
                    default:{
                        std::cout << "\nPlease only enter values between 1 and 10";
                        valid_input = false;
                        break;
                    }

                }
                if(valid_input)
                    
                    std::cout << "\n" << (digit == 0? 5 : digit) << " = " << numeral;
                
                break;
            }
            case  3:{
                short day, month, year;
                do{
                    std::cout << "\nEnter a date in numeric form: ";
                    std::cout << "\nEnter a month (MM): ";
                    std::cin >> month;
                    std::cout << "Enter a day (DD): ";
                    std::cin >> day;
                    std::cout << "Enter a year (YY): ";
                    std::cin >> year;
                    if(year > 99 || month > 12 || day > 31 || year < 1 || month < 1 || day < 1){ //Basic Input Validation
                        std::cout << "\nMONTH VALID RANGE: 1 - 12";
                        std::cout << "\nDAY VALID RANGE: 1 - 31";
                        std::cout << "\nYEAR VALID RANGE: 1 - 99\n";
                    }
                }while(year > 99 || month > 12 || day > 31 || year < 1 || month < 1 || day < 1);

                std::cout << "\n" << month << "/" << day << "/" << year;
                std::cout << (day * month == year? " is" : " is not") << " a magic date";
                break;

            }
            case  4:{
                float dimensions[2][3];
                for(short count = 0; count < 2; count++){
                do{
                    std::cout << "\nEnter the length and with for rectangle " << (count + 1) << ": ";
                    std::cout << "\n\nLength: ";
                    std::cin >> dimensions[count][0];
                    std::cout << "Width: ";
                    std::cin >> dimensions[count][1];
                    if(dimensions[count][0] < 0 || dimensions[count][1] < 0)
                        std::cout << "\nDimensions cannot be negative\n";
                }while(dimensions[count][0] < 0 || dimensions[count][1] < 0);
                    dimensions[count][2] = dimensions[count][0] * dimensions[count][1];
                }
                
                std::cout << "\nLargest Area: " <<
                (dimensions[0][2] == dimensions[1][2]? "The rectangles are equal": 
                dimensions[0][2] < dimensions[1][2]?  "Rectangle 2" : "Rectangle 1");
                break;
            }
            case  5:{
                const float BMI_BENCHMARKS[] = {18.5, 25};
                float weight, height, BMI;

                do{                
                    std::cout << "\nEnter weight (lb): ";
                    std::cin >> weight;
                    std::cout << "Enter height (in): ";
                    std::cin >> height;
                    if(weight < 0 || height < 0)
                        std::cout << "\nWEIGHT AND HEIGHT MUST BE POSITIVE\n";
                }while(weight < 0 || height < 0);

                BMI = weight * 703 / pow(height, 2);
                std::cout << "\nBMI: " <<
                (BMI < BMI_BENCHMARKS[0]? "Underweight" : BMI <= BMI_BENCHMARKS[1]? "Optimal" : "Overweight");
                break;
            }
            case  6:{
                const float NEWTON_LIMITS[]={10, 10000}, G_CONSTANT = 9.8;
                float weight;
                do{
                    std::cout << "\nEnter the mass of the object: ";
                    std::cin >> weight;
                    if(weight < 0)
                        std::cout << "\nMass must be positive\n";
                }while(weight < 0);

                weight *= G_CONSTANT;
                std::cout << "\nWeight: " << weight << " " <<
                (weight < NEWTON_LIMITS[0]? "TOO LIGHT" : weight > NEWTON_LIMITS[1]? "TOO HEAVY" : "");
                break;
                
            }
            case  7:{
                unsigned int seconds;
                do{
                    std::cout << "\nEnter a number of seconds: ";
                    std::cin >> seconds;
                    if(seconds < 0)
                        std::cout << "\nThe number of seconds must be positive";
                }while(seconds < 0);

                if(seconds >= 60){
                    std::cout << "\nMinutes: " << std::setw(6) << seconds / 60;
                    if(seconds >= 3600)
                        std::cout << "\nHours: " << std::setw(6) << seconds / 3600;
                        if(seconds >= 86400)
                            std::cout << "\nDays: " << std::setw(6) <<  seconds / 86400;
                }
                break;
            }
            case  8:{
                short choice;
            
                do{
                    std::cout << "\nWhat colors do you want to mix: ";
                    std::cout << "\n\n1. Blue and Red\n2. Blue and Yellow\n3. Red and Yellow";
                    std::cout << "\n\nSelection: ";
                    std::cin >> choice;
                    if(choice < 1|| choice > 3)
                    std::cout << "\nNot a valid combination\n";
                }while(choice < 1 || choice > 3);

               std::cout << "\nThat makes " << (choice < 2? "Purple": choice < 3? "Green" : "Orange");
               break;



            }
            case  9:{
                const float COIN_VALUES[] = {0.01, 0.05, 0.10, 0.25};
                const std::string COINT_NAMES[] = {"Pennies", "Nickels", "Dimes", "Quarters"};
                float coin_freq[4], dollar = 0;

                std::cout << "\nEnter a combination of coins and see if they add up to a dollar: \n\n";
                for(short i = 0; i < 4; i++){
                    do{
                        std::cout << COINT_NAMES[i] << ": ";
                        std::cin >> coin_freq[i];
                        if(coin_freq[i] < 0)
                            std::cout << "\nThe number of " << COINT_NAMES[i] << " must be positive\n\n";
                    }while(coin_freq[i] < 0);
                    dollar += coin_freq[i] * COIN_VALUES[i];
                }
                
                std::cout << "\nThat's" << (dollar == 1? "" : dollar < 1? " less than" : " more than") << " a dollar";
                break;
            }
            case 10:{
                int year, month, days;
                do{
                    std::cout << "\nEnter a year and a month: ";
                    std::cout << "\n\nYear (YYYY): ";
                    std::cin >> year;
                    std::cout << "Month (MM): ";
                    std::cin >> month;

                    if(year < 1 || year > 9999|| month < 1 || month > 12){
                        std::cout << "\nYear must be within 1 and 9999";
                        std::cout << "\nMonth bust be within 1 and 23\n";
                    }
                }while(year < 1 || year > 9999 || month < 1 || month > 12);

                if(month == 2){
                    if((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
                        days = 29;
                    else
                        days = 28;
                }
                else if((month <= 7 && month % 2 != 0) || (month > 7 && month % 2 == 0))
                    days = 31;
                else
                    days = 30;

                std::cout << "\n" << days << " days";
                break;

            }
            case 11:{
                unsigned seed = time(0);
                srand(seed);

                short fst_val, snd_val, ans_val, usr_val;
                fst_val = rand();
                snd_val = rand();
                ans_val = fst_val + snd_val;

                std::cout << "\n" << std::setw(8) << fst_val;
                std::cout << "\n" << std::setw(8) << snd_val;
                std::cout << "\n+ ------";
                std::cout << "\n\nAnswer: ";
                std::cin >> usr_val;
                
                std::cout << "\n" << (usr_val == ans_val? "Congrats! That's the right answer" : "Wrong!");
                std::cout << "\n\nRight answer: " << std::setw(8) << ans_val;
                std::cout << "\nYour answer: " << std::setw(9) << usr_val;
                break;
            }
            case 12:{
                const float PRICE = 99,
                            DISCOUNTS_RATES[] = {0.20, 0.30, 0.40, 0.50};
                            DISCOUNT_LIMITS[] = {10, 19, 49, 99 }
                short quantity;
                do{
                    std::cout << "\nEnter purchase quantity: ";
                    std::cin >> quantity;
                    if(quantity < 1)
                        std::cout << "\nThere must be at least one item in the purchase\n";
                }while(quantity < 1);


            }
            default:
                std::cout << "\nINVALID INPUT";
                break;
        }

        
        std::cout << "\n";
    }while(choice != 25);
}