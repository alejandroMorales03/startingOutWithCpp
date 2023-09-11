#include <iostream>
#include <iomanip>
#include <cmath>


int main(){
    char choice;
    do{
        do{
            std::cout << "\nPrograms from Chapter 4\n";
            std::cout << "\n 1. Minimum/Maximum\n 2. Roman Numeral Calculator\n 3. Magic Dates";
            std::cout << "\n\nSelection: ";
            std::cin >> choice;
            std::cin.ignore();
            if(!isdigit(choice))
                std::cout << "\nONLY ENTER NUMBERS PLEASE\n";
        }while(!isdigit(choice));

        std::cout << std::setprecision(2) << std::fixed;
        short selection = static_cast<int>(choice) - 48;
        
        switch(selection){
            case 1:{
                float fval, sval;
                std::cout << "\nEnter two numbers separated by a space: ";
                std::cin >> fval >> sval;  
                std::cout << "\n" << (fval > sval? fval : sval) << " is the largest";
                std::cout << "\n" << (fval < sval? fval : sval) << " is the smallest";
                break;
            }
            case 2:{
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
            case 3:{
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
            case 4:{
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
            case 5:{
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
            default:
                std::cout << "\nINVALID INPUT";
                break;
        }

        
        std::cout << "\n";
    }while(choice != 25);
}