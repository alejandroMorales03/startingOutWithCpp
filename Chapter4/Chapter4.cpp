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
        std::cout << "\n10. Days in a Month \n11. Math Tutor\n12. Software Sales";
        std::cout << "\n13. Book Club Points\n14. Bank Charges\n15. Shipping Charges";
        std::cout << "\n16. Running the Race\n17. Personal Best\n18. Fat Gram Calculator";
        std::cout << "\n19. Spectral Analysis\n20. The Speed of Sound\n21. The Speed of Sound in Gasses";
        std::cout << "\n22. Feezing and Boiling Points\n23. Geometry Calculator\n24. Long-Distance Calls";
        std::cout << "\n25. Mobile Service Provider \n26. Mobile Service Provider Part 2\n27. Mobile Service Provider Part 3";
        std::cout << "\n28. Quit";
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
            
                short sold_units;
                
                do{
                    std::cout << "\nEnter how many units were sold: ";
                    std::cin >> sold_units;
                    if(sold_units < 1)
                        std::cout << "\nAt least one unit must be sold to complete the transaction\n";
                }while(sold_units < 1);

                const float DISCOUNTS[] = {.50, .40, .30, .20};
                const float LOW_LIMITS[] = {100, 50, 20, 10};
                const float RETAIL_PRICE = 99;
                float final_price = sold_units * RETAIL_PRICE;
                bool found = false;

                for(short index = 0; index < sizeof(DISCOUNTS)/sizeof(DISCOUNTS[0]) && !found; index++){
                    if(sold_units >= LOW_LIMITS[index]){
                        found = true;
                        final_price *= 1 - DISCOUNTS[index];
                    }
                }

                std::cout << "\nFinal Cost: $ " << final_price;
                break; 

            }
            case 13:{
                const short BOOKS[] = {4, 3, 2, 1, 0};
                const short POINTS[] = {60, 30, 15, 5, 0};
                short read;

                do{
                    std::cout << "\nHow many books did you read: ";
                    std::cin >> read;
                    if(read < 0)
                        std::cout << "\nInvalid Input\n";
                }while(read < 0);

                bool found = false;
                for(short index = 0; !found && index < sizeof(BOOKS)/ sizeof(BOOKS[0]); index++){
                    if(read >= BOOKS[index]){
                        found = true;
                        std::cout << "\n" << POINTS[index] << " points";
                    }
                }
                break;
            }
            case 14:{
                const float MONTHLY_FEE = 10, BAL_UNDER_400_FEE = 15;
                const float CHECK_FEES[] = {0.04, 0.06, 0.08, .10};
                const short CHECKS[] = {60, 40, 20, 0};

                float balance, fees = 10;;
                short checks;
                bool found = false;

                do{
                    std::cout << "\nEnter current balance: ";
                    std::cin >> balance;
                    std::cout << "Enter number of checks written: ";
                    std::cin >> checks;
                    if(checks < 0)
                        std::cout << "\nINVALID INPUT FOR CHECKS FIELD\n";
                }while(checks < 0);

                if(balance< 400){
                    fees += 15;
                    if(fees < 0)
                        std::cout << "\nAccount is overdrawn";
                }
          
                for(short index = 0; !found && index < sizeof(CHECK_FEES)/sizeof(CHECK_FEES[0]); index++){
                    if(checks >= CHECKS[index]){
                        found = true;
                        fees += checks * CHECK_FEES[index];
                    }
                }

                std::cout << "\nMonthly Service Fee: $ " << fees;
                break;
            }
            case 15:{
                float weight, miles, price;
                const float LOWER_LIMITS[] = {10, 6, 2, 0};
                const float RATES[] = {4.80, 3.70, 2.20, 1.10};

                bool found = false;

                do{
                    std::cout << "\nEnter the weight of the package in kg: ";
                    std::cin >> weight;
                    std::cout << "Enter the distance in miles: ";
                    std::cin >> miles;
                    if(!(weight <= 20 && weight > 0 && miles >= 10 && miles <= 3000)){
                        std::cout << "\nWEIGHT MUST BE WITHIN 0 - 20 kg (0 not inclusive)";
                        std::cout << "\nDISTANCE MUST BE WITHIN 10 - 3000 miles\n";
                    }
                }while(!(weight <= 20 && weight > 0 && miles >= 10 && miles <= 3000));

                miles /=500;
                for(short index = 0;!found && index < sizeof(LOWER_LIMITS)/sizeof(LOWER_LIMITS[0]); index++){
                    if(weight > LOWER_LIMITS[index]){
                        price = miles * RATES[index];
                        found = true;
                    }
                }
                std::cout << "\nTotal: $ " << price;
                break;
            }
            case 16:{
                short time_one, time_two, time_three;
                do{
                    std::cout << "\nEnter the times for thre runners in seconds: ";
                    std::cin >> time_one >> time_two >> time_three;
                    if(time_one < 0 || time_two < 0 || time_three < 0)
                        std::cout << "\nAll times must be positive\n";
                }while(time_one < 0 || time_two < 0 || time_three < 0);

                if(time_one < time_two && time_one < time_three){
                    std::cout << "\nFirst place: Runner 1";
                    if(time_two < time_three){
                        std::cout << "\nSecond place: Runner 2";
                        std::cout << "\nThird place: Runner 3";
                    }
                    else{
                        std::cout << "\nSecond place: Runner 3";
                        std::cout << "\nThird place: Runner 2";
                    }
                }

                if(time_two < time_one && time_two < time_three){
                    std::cout << "\nFirst place: Runner 2";
                    if(time_one < time_three){
                        std::cout << "\nSecond place: Runner 1";
                        std::cout << "\nThird place: Runner 3";
                    }
                    else{
                        std::cout << "\nSecond place: Runner 3";
                        std::cout << "\nThird place: Runner 1";
                    }
                }
         
                if(time_three < time_one && time_three < time_two){
                    std::cout << "\nFirst place: Runner 3";
                    if(time_two < time_one){
                        std::cout << "\nSecond place: Runner 2";
                        std::cout << "\nThird place: Runner 1";
                    }
                    else{
                        std::cout << "\nSecond place: Runner 1";
                        std::cout << "\nThird place: Runner 2";
                    }
                }
                break;
            }
            case 17:{
                std::string dates[3];
                float heights[3];

                for(short index = 0; index < 3; index++){
                    std::cout << "\nEnter date (Month DD, YYYY): ";
                    std::cin.ignore();
                    getline(std::cin, dates[index]);
                    do{
                        std::cout << "Enter height in meters: ";
                        std::cin >> heights[index];

                        if(heights[index] < 2 || heights[index] > 5)
                            std::cout << "\nHeight must be within 2 and 5\n\n";
                    }while(heights[index] < 2 || heights[index] > 5);    
                }
                
                bool swap = false;
                float temp;
                std::string temp_s;
                do{
                    swap = false;
                    for(short index = 0; index < 2; index++){
                        if(heights[index] < heights[index + 1]){
                            temp = heights[index];
                            heights[index] = heights[index + 1];
                            heights[index + 1] = temp;

                            temp_s = dates[index];
                            dates[index] = dates[index + 1];
                            dates[index + 1] = temp_s;
                            swap = true;
                        }
                    }

                }while(swap);

                for(short index = 0; index < 3; index++){
                    std::cout << "\n" << dates[index] << ": " << heights[index] << " meters";
                }
                break;
            
            }
            case 18:{
                short calories;
                float fat_grams;
                do{
                    std::cout << "\nEnter total calories: ";
                    std::cin >> calories;
                    std::cout << "\nEnter fat grams: ";
                    std::cin >> fat_grams;
                    if(calories < 0 || fat_grams < 0){
                        std::cout << "\nCalories and fat grams must be positive numbers\n";
                    }

                }while(calories < 0 || fat_grams < 0);

                float cal_from_fat = fat_grams * 9, fat_cal_pctage = cal_from_fat/calories * 100;
                
                if(cal_from_fat > calories)
                    std::cout << "\nYou must have entered either the total calories or the gram fats incorrectly!";
                else
                    std::cout << "\n" << fat_cal_pctage << " percent of the calories come from fat. " << (fat_cal_pctage < 30? " That food is low in fat!" : "");
                break;
            }
            case 19:{
                bool found = false;
                float user_wavelength;
                const float WAVELENGTHS[7] = {1e-11, 1e-8, 4e-7, 7e-7, 1e-3, 1e-2, };
                const std::string Names[7] = {"Gamma Rays", "X Rays", "Ultraviolet", "Visible Light", "Infrared", "Microwaves", "Radio Waves"};

                do{
                    std::cout << "\nEnter a wavelength in meters: ";
                    std::cin >> user_wavelength;
                    if(user_wavelength < 0)
                        std::cout << "\nWavelengths must be positive\n";
                }while(user_wavelength < 0);
                
                for(short index = 0; !found && index < 7; index++){
                    if(user_wavelength <= WAVELENGTHS[index]){
                        std::cout << "\n" << Names[index];
                        found = true;
                    }
                }
                if(!found)
                    std::cout << Names[6];
                break;
            }
            case 20:{
                short selection;
                float distance;
                const short SPEEDS[] = {1100, 4900, 16400};
                do{
                    std::cout << "\nSelect a medium:\n\n1. Air\n2. Water\n3. Steel";
                    std::cout << "\n\nSelection: ";
                    std::cin >> selection;
                    std::cout << "Enter a distance in feet: ";
                    std::cin >> distance;
                    if(selection < 1 || selection > 3||distance < 0)
                        std::cout << "\nINVALID INPUT\n";
                }while(selection < 1 || selection > 3||distance < 0);
                
                std::cout << "Time: " << distance * 1/SPEEDS[selection - 1];
                break;   
            }
            case 21:{
                float seconds, distance;
                short selection;
                float SPEED[] = {258.0, 331.5, 972.0, 1270.0};

                do{
                    std::cout << "\nSelect a medium: \n\n1. Carbon Dioxide\n2. Air\n3. Helium\n4. Hydrogen\n\n";
                    std::cout << "Selection: ";
                    std::cin >> selection;
                    if(selection < 1 || selection > 4)
                        std::cout << "\nInvalid Input\n";
                }while(selection < 1 || selection > 4);
                
                do{
                    std::cout << "\nEnter the number of seconds it took the sound to travel: ";
                    std::cin >> seconds;

                    if(seconds <= 0)
                        std::cout << "\nSeconds must be greater than 0";
                }while(seconds <= 0);

                distance = seconds * 1/SPEED[selection - 1];
                std::cout << "\n" << "The sound travaled " << distance  << " meters.";
                break;
            }
            case 22:{
                const std::string SUBSTANCE_F[] = {"Oxygen", "Ethyl Alcohol", "Mercury", "Water"};
                const float FREEZING_POINT[] = {-362, -173, 38, 32};
                const std::string SUBSTANCE_B[] = {"Mercury", "WWater", "Ethyl Alcohol", "Oxygen"};
                const float BOILING_POINTS[] = {676, 212, 172, -306};
                float temperature;

                std::cout << "\nEnter a temperature in F: ";
                std::cin >> temperature;

                for(short count = 0; count < 4; count++){
                    if(temperature <= FREEZING_POINT[count])
                        std::cout  << "\n" << SUBSTANCE_F[count] << " will freeze";
                    if(temperature >= BOILING_POINTS[count])
                        std::cout  << "\n" << SUBSTANCE_B[count] << " will boil";
                }
                break;
            }
            case 23:{
                short choice;
                do{
                    std::cout << "\nSelect an option: ";
                    std::cout << "\n\n1. Calculate the Area of a Circle\n2. Calculate the Area of a Rectangle";
                    std::cout << "\n3. Calculate the Area of a Trianble\n4. Quit\n\nSelection: ";
                    std::cin >> choice;
                    if(choice < 1 || choice > 4)
                        std::cout << "\nInvalid Input\n";
                }while(choice < 1 || choice > 4);

                switch(choice){
                    case 1:{
                        float radius;
                        const float PI = 3.14159;
                            do{
                                std::cout << "\nEnter the radius: ";
                                std::cin >> radius;

                                if(radius < 0)
                                    std::cout << "\nRadius must be a positive numer\n";

                            }while(radius < 0);
                            std::cout << "Area: " << PI * pow(radius, 2);
                            break;
                    }
                    case 2:{
                        float width, length;
                        do{
                            std::cout << "\nEnter the length and width of rectangle: ";
                            std::cin >> length >> width;

                            if(length < 0 || width < 0 )
                                std::cout << "\nLength and width must be positive\n";
                        }while(length < 0 || width < 0);
                        
                        std::cout << "Area: " << length * width;
                        break;
                    }
                    case 3:{
                        float base, height;
                        do{
                            std::cout << "\nEnter base and height: ";
                            std::cin >> base >> height;
                            if(base < 0 || height < 0)
                                std::cout << "\nBase and Height must be positive\n";
                        }while(base < 0 || height < 0);

                        std::cout << "Area: " << base * height * .5;
                        break;
                    }
                    case 4:{
                        std::cout << "\nShutting Down\n";
                        break;
                    }
                }
                break;
            }
            case 24:{
                float starting_time, minutes;
                const float LOWER_LIMTS[] = {19.01, 7.00, 0};
                const float RATES[] = {0.20, 0.45, 0.05};

                do{
                    std::cout << "\nEnter starting time of call (HH.MM): ";
                    std::cin >> starting_time;
                    std::cout << "How many minutes was the call: ";
                    std::cin >> minutes;
                    if(starting_time < 0 || starting_time > 23.59)
                        std::cout << "\nStarting time must be within 0 and 23:59\n";
                    if((starting_time - static_cast<int>(starting_time)) >= 60)
                        std::cout << "\n.MM must not be greater than 59\n";
                    if(minutes < 0)
                        std::cout << "\nMinutes cannot be less than 0\n";
                }while(starting_time < 0 || starting_time > 23.59 || (starting_time - static_cast<int>(starting_time) >= 50)||minutes < 0);

                bool found = false;
                float total;
                for(short index = 0; !found && index < 4; index++){
                    if(starting_time > LOWER_LIMTS[index]){
                        found = true;
                        total = minutes * RATES[index];
                    }
                }
                std::cout << "\nPrice: $ " << total;
                break;
            }
            case 25:
            case 26:
            case 27:{
                short package, minutes;
                float total = 0;
                
                do{
                    std::cout << "\nWhich package do you have? \n\n1. Package A\n2. Package B\n3. Package C\n";
                    std::cout << "\nSelection: ";
                    std::cin >> package;
                    std::cout << "\nHow many minutes were consumed: ";
                    std::cin >> minutes;
                    if(package < 1 || package > 3)
                        std::cout << "\nINVALID INPUT\n";
                    if(minutes < 0)
                        std::cout << "\nMinutes cannot be negative\n";
                }while(package < 1 || package > 3 || minutes < 0);

                switch(package){
                    case 1:{
                        const float AVA_MIN = 450, FLAT_RATE = 39.99, ADD_MIN_RATE = 0.45;
                        if(minutes > AVA_MIN)
                            total = ADD_MIN_RATE * (minutes - AVA_MIN);

                        total += FLAT_RATE;
                        std::cout << "\nTotal Due: $ " << total;                       
                        break;
                    }
                    case 2:{
                        const float AVA_MIN = 900, FLAT_RATE = 59.99, ADD_MIN_RATE = 0.40;
                        if(minutes > AVA_MIN)
                            total = ADD_MIN_RATE * (minutes - AVA_MIN);

                        total += FLAT_RATE;
                        std::cout << "\nTotal Due: $ " << total;
                        break;
                    }
                    case 3:{
                        const float FLAT_RATE = 69.99;
                        total += FLAT_RATE;
                        std::cout << "\nTotal Due: $ " << total;
                        break;
                    }
                }
            break;
            }
            case 28:{
                std::cout << "\nSHUTTING DOWN";
                break;
            }
            default:
                std::cout << "\nINVALID INPUT";
                break;
        }

        
        std::cout << "\n";
    }while(choice != 25);
    return 0;
}