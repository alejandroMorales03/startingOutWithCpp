#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    char choice;
    do{
        do{
            do{
                std::cout << "\nPROGRAMS FROM CHAPTER 3";
                std::cout << "\n\nA. Miles Per Gallon\nB. Stadium Seating\nC. Test Average";
                std::cout << "\nD. Average Rainfall\nE. Male and Female Percentages\nF. Ingredient Adjuster";
                std::cout << "\nG. Box Office\nH. How Many Widgets\nI. How Many Calories";
                std::cout << "\nJ. How Much Insurance\nK. Automobile Costs\nL. Celsius to Fahrenheit";
                std::cout << "\nM. Currency\nN. Monthly Sales Tax\nO. Property Tax\nP. Senior Citizen Property Tax";
                std::cout << "\n\nSELECTION: ";
                std::cin.get(choice);
                if(!isalpha(choice) || islower(choice)){
                    std::cin.ignore(20, '\n');
                    std::cout << "\nPLEASE ENTER CAPITAL LETTERS ONLY\n";
                }
            }while(!isalpha(choice) || islower(choice));
            

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
                    
                    std::cin.ignore();
                    do{
                        do{
                            std::cout << "\nTicket Prices\n\nClass A: $ 15.00\tClass B: $ 12.00\nClass C: $  9.00\n";
                            std::cout << "\nEnter D to finish buying\n";
                            std::cout << "\nWhich ticket class would you like: ";
                            
                            std::cin.get(ticket);
                            if(ticket != 'D')
                                std::cin.ignore();
                            
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
                            std::cin.ignore();
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
                    std::cout << "\nAverage Male Enrollment: " << std::setw(7) << male_avg << " %";
                    std::cout << "\nAverage Female Enrollment: " << std::setw(5) << fem_avg << " %";
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
                    const float NET_PROFIT_RATE = 0.20, ADULT_PRICE = 10.00, CHILD_PRICE = 6.00;
                    
                    std::string mov_name;

                    short adult_tckt, child_tckt;
                    float gross_profit, net_profit, distributor_amout;

                    std::cout << "\nEnter name of movie: ";
                    getline(std::cin, mov_name);
                    std::cout << "Enter number of adult tickets sold: ";
                    std::cin >> adult_tckt;
                    std::cout << "Enter number of child tickets sold: ";
                    std::cin >> child_tckt;

                    gross_profit = child_tckt * CHILD_PRICE + adult_tckt * ADULT_PRICE;
                    net_profit = gross_profit * NET_PROFIT_RATE;
                    distributor_amout = gross_profit - net_profit;

                    std::cout << "\nMovie Name: " << mov_name;
                    std::cout << "\nAdult Tickets Sold: " << std::setprecision(2) << std::fixed << std::setw(20) << adult_tckt;
                    std::cout << "\nChild Tickets Sold: " << std::setprecision(2) << std::fixed << std::setw(20) << child_tckt;
                    std::cout << "\nGross Box Office Profit: $ " << std::setprecision(2) << std::fixed << std::setw(13) << gross_profit;
                    std::cout << "\nNet Box Office Profit: $ " << std::setprecision(2) << std::fixed << std::setw(15) << net_profit;
                    std::cout << "\nAmount Paid to Distributor: $ " << std::setprecision(2) << std::fixed << std::setw(10) << distributor_amout;
                    break;  
                }
                case 'H':{
                    const float IND_WIDGET_WEIGHT = 12.5;
                    float pallet_weight, total_weight;
                    int number_widgets;

                    std::cout << "\nEnter total weight in lb (pallet + stacked widgets): ";
                    std::cin >> total_weight;
                    std::cout << "Enter weight of pallet by itself: ";
                    std::cin >> pallet_weight;

                    number_widgets = (total_weight - pallet_weight) / IND_WIDGET_WEIGHT;

                    std::cout << "\nNumber of widgets on pallet: " << number_widgets;
                    break;

                }
                case 'I':{
                    const float SERVING_TO_COOKIE_RATE = 0.33333, CALORIES_PER_SERVING = 300;
                    float cookies, consumed_calories;

                    std::cout << "\nEnter how many cookies did you eat: ";
                    std::cin >> cookies;

                    consumed_calories = round(cookies * SERVING_TO_COOKIE_RATE * CALORIES_PER_SERVING);

                    std::cout << "\nConsumed Calories: " << consumed_calories;
                    break;
                }
                case 'J':{
                    const float REC_INS_RATE = .80;
                    float replacement_cost, recommend_ins_amt;

                    std::cout << "\nEnter replacement cost of property: ";
                    std::cin >> replacement_cost;
                    
                    recommend_ins_amt = REC_INS_RATE * replacement_cost;
                    
                    std::cout << "\nRecommened Insurance Amount: $ " << recommend_ins_amt;
                    break; 

                }
                case 'K':{
                    float loan_pay_exp, ins_exp, gas_exp, oil_exp, tires_exp, maint_exp;
                    float monthly_cost, annual_cost;

                    std::cout << "\nEnter monthly loan payment amount: ";
                    std::cin >> loan_pay_exp;
                    std::cout << "Enter monthly insurance amount: $ ";
                    std::cin >> ins_exp;
                    std::cout << "Enter gas expenses: $ ";
                    std::cin >> gas_exp;
                    std::cout << "Enter oil expenses: $ ";
                    std::cin >> oil_exp;
                    std::cout << "Enter tires expenses: $ ";
                    std::cin >> tires_exp;
                    std::cout << "Enter maintenance expenses: $ ";
                    std::cin >> maint_exp;

                    monthly_cost = loan_pay_exp + ins_exp + gas_exp + oil_exp + tires_exp + maint_exp;
                    annual_cost = 12 * monthly_cost;

                    std::cout << "\nMonthly Cost: $ " << std::setw(6) << monthly_cost;
                    std::cout << "\nAnnual Cost: $ " << std::setw(7) << annual_cost; 
                    break;
                }
                case 'L':{
                    float celsius, fahrenheit;

                    std::cout <<"\nEnter temperature in degree Celsius: ";
                    std::cin >> celsius;

                    fahrenheit = 9/5.0 * celsius + 32;

                    std::cout << "\nCelsius: " << std::setw(9) << celsius;
                    std::cout << "\nFarenheit: " << std::setw(7) << fahrenheit;
                    break;

                }
                case 'M':{
                    const float YEN_PER_DOLLAR = 98.93, EURO_PER_DOLLAR = 0.74;
                    float us_dollar;

                    std::cout << "\nEnter dollar amount: $ ";
                    std::cin >> us_dollar;

                    std::cout << "\nEuros: " << std::setw(6) << EURO_PER_DOLLAR * us_dollar;
                    std::cout << "\nYen: " << std::setw(8) << YEN_PER_DOLLAR * us_dollar;
                    break;
                }
                case 'N':{
                   const float COUNTY_TAX_RATE = 0.02, STATE_TAX_RATE = 0.04;
                   std::string month;
                   float total_collected, sales;

                   std::cout << "\nEnter total collected: $ " ;
                   std::cin >> total_collected;
                   sales = total_collected / (COUNTY_TAX_RATE + STATE_TAX_RATE + 1);
                   std::cout << "\nMonth: " << month << "\n";
                   for(float index = 0; index < ("Month: " + month).length(); index++)
                        std::cout << "-";
                    std::cout << "\nTotal Collected: $ " << std::setw(10) << total_collected;
                    std::cout << "\nSales: $ " << std::setw(20) << sales;
                    std::cout << "\nCounty Sales Tax: $ " << std::setw(9) << sales * COUNTY_TAX_RATE;
                    std::cout << "\nState Sales Tax: $ " << std::setw(10) << sales * STATE_TAX_RATE;
                    std::cout << "\nTotal Sales Tax: $ " << std::setw(10) << sales * (COUNTY_TAX_RATE + STATE_TAX_RATE);
                    break;

                }
                case 'O':{
                    const float PROPERTY_TAX_RATE = .0075, ASSMT_RATE = 0.60;
                    float prpty_actual_val, assmt_val, property_tax;

                    std::cout << "\nEnter actual value of property: $ ";
                    std::cin >> prpty_actual_val;
                    assmt_val = prpty_actual_val * ASSMT_RATE;
                    property_tax = assmt_val * PROPERTY_TAX_RATE;

                    std::cout << "\nProperty Assessment Value: $" << std::setw(10) <<  assmt_val;
                    std::cout << "\nProperty Tax: $ " << std::setw(22) << property_tax;
                    break;
                }
                case 'P':{
                    const float PROPERTY_TAX_RATE = .0264, ASSMT_RATE = 0.60, SENIOR_EXP = 5000;
                    float prpty_actual_val, assmt_val, property_tax, qtly_payment;

                    std::cout << "\nEnter actual value of property: $ ";
                    std::cin >> prpty_actual_val;
                    assmt_val = prpty_actual_val * ASSMT_RATE - 5000;
                    property_tax = assmt_val * PROPERTY_TAX_RATE;
                    qtly_payment = property_tax / 4;

                    std::cout << "\nProperty Tax: $ " << std::setw(14) << property_tax;
                    std::cout << "\nQuaterly Payment: $ " << std::setw(10) << qtly_payment;

                }
                default:{
                    std::cout << "\n\nINVALID INPUT";
                    break;
                }
            }
            std::cout << "\n\n";
            if(isalpha(choice))
                std::cin.ignore();
        

            
        }while(choice < 'A'|| choice > 'Y');
}while(choice != 'Z');
}