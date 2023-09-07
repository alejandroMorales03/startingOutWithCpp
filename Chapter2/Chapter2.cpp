/**
 * @brief List of Programs from Chapter 2 of Starting Out with C++
 * @author Alejandro Morales
 * @version v1.0
 */

#include <iostream>



int main(){
    short option;
    
    do{
        do{
            std::cout << "\nPrograms from Chapter 2:\n";
            std::cout << "\n 1. Sum of Two Numbers\n 2. Sales Prediction";
            std::cout << "\n 3. Sales Tax\n 4. Restaurant Bill";
            std::cout << "\n 5. Average of Values\n 6. Annual Pay";
            std::cout << "\n 7. Ocean Levels \n 8. Total Purchase"; 
            std::cout << "\n 9. Cyborg Data Tyope Sizes\n10. Miles Per Gallon "; 
            std::cout << "\n11. Distance Per Tank of Gass\n12. Land Calculation"; 
            std::cout << "\n13. Circuit Board Price\n14. Personal Information";
            std::cout << "\n15. Triangle Pattern\n16. Diamond Pattern";
            std::cout << "\n17. Stock Comission\n18. Energy Drink COnsumption";
            std::cout << "\n19. Quit\n\nChoice: ";
            std::cin >> option;
            

        
            switch(option){
                case  1:{
                    short no1 = 50, no2 = 100, sum = no1 + no2;
                    std::cout << "\nSum of " << no1  << " and " << no2 << " is " << sum;
                    break;
                }
                case  2:{
                    const float TOTAL_SALES = 8600000;
                    float east_cost_prod_rate = .58;
                    std::cout << "\nEast Coast will produce " << TOTAL_SALES * east_cost_prod_rate;
                    break;
                }
                case  3:{
                    float total_purchase = 95;
                    const float STATE_TAX_RATE = 0.04, COUNTRY_TAX_RATE = 0.02;
                    std::cout << "\nPurchase:    $ " << total_purchase;
                    std::cout << "\nSTATE TAX:   $ " << total_purchase * STATE_TAX_RATE;
                    std::cout << "\nCOUNTRY TAX: $ " << total_purchase * COUNTRY_TAX_RATE;
                    std::cout << "\nTOTAL:       $ ";
                    std::cout << total_purchase + total_purchase * (STATE_TAX_RATE + COUNTRY_TAX_RATE);
                    break;
                }
                case  4:{
                    float total = 88.67;
                    const float TAX_RATE = 0.0675, TIP_RATE = 0.20;
                    std::cout << "\nSubtotal:  $ " << total;
                    std::cout << "\nAfter Tax: $ " << total * (TAX_RATE + 1);
                    std::cout << "\nTip:       $ " << (total * (TAX_RATE + 1)) * TIP_RATE;
                    std::cout << "\nTotal:     $ ";
                    std::cout << (total * (TAX_RATE + 1)) * (TIP_RATE + 1);
                    break;
                }
                case  5:{
                    short values[] = {28, 32, 37, 24, 33};
                    short sum = 0; 
                    for(short index = 0; index < 5; index++)
                        sum += values[index];
                    std::cout << "\nAverage: " << static_cast<double>(sum)/5;
                    break;
                }
                case  6:{
                    float pay_amount = 2200.0;
                    short pay_periods = 26;
                    float annual_pay = pay_amount * pay_periods;
                    std::cout << "\nAnnual Pay: " << annual_pay;
                    break;
                }
                case  7:{
                    short years[] = {5, 7, 10};
                    for(short i = 0; i < 3; i++){
                        std::cout << "\nIn " << years[i] << " years the ocean will be ";
                        std::cout << 1.5 * years[i] << " higher";
                    }
                    break;
                }
                case  8:{
                    float prices[] = {15.95, 24.95, 6.95, 12.95, 3.95};
                    float total = 0;
                    const float TAX_RATE = 0.07;

                    for(short index = 0; index < 5; index++){
                        std::cout << "\nItem " << (index + 1) << ": $ " << prices[index];
                        total += prices[index];
                    }
                    std::cout << "\n\nSubtotal: $: " << total; 
                    std::cout << "\nTax:      $: " << total * TAX_RATE;
                    std::cout << "\nTotal:    $: " << total * (1 + TAX_RATE);
                    break;
                }
                case  9:{
                    std::cout << "\nChar:   " << sizeof(char) << " bytes";
                    std::cout << "\nInt:    " << sizeof(int) << " bytes";
                    std::cout << "\nDouble: " << sizeof(double) << " bytes";
                    std::cout << "\nFloat:  " << sizeof(float) << " bytes";
                    break;
                    
                }
                case 10:{
                    float gallons = 15, miles  = 375;
                    std::cout << "\nMPG: " << miles / gallons;
                    break;  
                }
                case 11:{
                    float gallons = 20;
                    const float DRIV_TOWN_MPG = 23.5, DRIV_HWAY_MPG = 28.9;
                    std::cout << "\nTown Distance:    " << gallons * DRIV_TOWN_MPG << " miles.";
                    std::cout << "\nHighway Distance: " << gallons * DRIV_HWAY_MPG << " miles.";
                    break;
                }
                case 12:{ 
                    float square_feet = 391876;
                    const float SQUARE_FEET_PER_ACRE = 43560;
                    std::cout << "\nSquare Feet\tAcres";
                    std::cout << "\n" << square_feet << "\t\t" << (square_feet / SQUARE_FEET_PER_ACRE);
                    break;
                }
                case 13:{
                    const float PROFIT_RATE = 1.35;
                    float cost = 14.95;
                    std::cout << "\nSelling price $ " << PROFIT_RATE * cost;
                }
                case 14:{
                    std::string name = "Alejandro";
                    std::string address = "13031 SW 259th street, Homestead, Florida, 33023";
                    std::string phone_nuber = "(786) 576 - 8083";
                    std::string major = "Computer Science";

                    std::cout << "\nName:         " << name;
                    std::cout << "\nAddress:      " << address;
                    std::cout << "\nPhone Number: " << phone_nuber;
                    std::cout << "\nMajor:        " << major;
                    break;

                }
                case 15:{
                    for(short row = 1; row <= 4; row++){
                        std::cout << "\n";
                        for(short space = 0; space < 4 - row; space++){
                            std::cout << " ";
                        }
                        for(short start = 0; start < row + (row - 1); start++){
                            std::cout << "*";
                        }
                    }
                    break;
                }
                case 16:{
                    std::string copies[] ={"", "", ""};

                    for(short row = 1; row <= 7; row++){
                        std::cout << "\n";
                        if(row <= 4){    
                            for(short space = 0; space < 4 - row; space++)
                                std::cout << " ";
                            for(short star = 0; star < 2 * row - 1; star++){
                                std::cout << "*";
                                if(row <= 3)
                                    copies[3 - row] += "*";  
                            }
                        }
                        else{
                            for(short space = 0; space < row - 4; space++)
                                std::cout << " ";
                            std::cout << copies[row - 5];
                            }
                        }
                        break;
                }
                case 17:{
                    float shares = 750;
                    float price_per_share = 35.00;
                    float comission_rate = 0.02;

                    std::cout << "\nTotal paid for stock: " << shares * price_per_share;
                    std::cout << "\nComission Amount:     " << shares * price_per_share * comission_rate; 
                    std::cout << "\nTotal Paid:           " << shares * price_per_share * (comission_rate + 1); 
                    break;
                }
                case 18:{
                    float total_customer = 16500, 
                          once_wk_perc_rate = 0.15, 
                          citrus_flv_perc_rate = 0.58;

                    std::cout << "\nOnce a week buyers:   " << total_customer * once_wk_perc_rate;
                    std::cout << "\nCitrus Flavor buyers: " << total_customer * citrus_flv_perc_rate;
                    break;

                }
                case 19:{
                    std::cout << "\nSHUTTING DOWN...";
                    break;
                }
                default:{
                    std::cout << "\nINVALID INPUT";
                    std::cout << "\n";
                    break;
                }
            }
        }while(option < 1 || option > 19);
    }while(option != 19);
    


}