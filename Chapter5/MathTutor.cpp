#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){

    unsigned short choice;
    float value_one, value_two, user_answer, answer;

    do{
        cout << "\nWhat operation do you want to practice:";
        cout << "\n\n1. Addition\t\t2. Substraction\n3. Multiplication\t4. Division\n5. Quit";
        cout << "\n\nSelection: " ;
        cin >> choice;

        if(choice >= 1 && choice <= 4){
            unsigned seed = time(0);
            srand(seed);
            value_one = (rand() % (1000 - 0 + 1) + 0); 
            value_two = (rand() % (1000 - 0 + 1) + 0);
            cout << "\nHere are your numbers : " << value_one << " " << value_two << "\n";
        }

    

        switch(choice){
            case 1:
                answer = value_one + value_two;
                break;
            case 2:
                answer = value_one - value_two;
                break;
            case 3:
                answer = value_one * value_two;
                break;
            case 4:
                answer = value_one / value_two;
                if(answer != static_cast<int>(answer))
                    answer = static_cast<int>(answer * 1000)/1000.0;
                break;
            case 5:
                cout << "\nSHUTTING DOWN...\n\n";
                break;
            default:
                cout << "\nINVALID INPUT\n* Available options are 1 through 5\n";
                break;
        }
        if(choice >= 1 && choice <= 4){
            cout << "\nEnter your answer (3 decimal places of precision): ";
            cin >> user_answer;

            user_answer == answer? cout << "\nThat's right" : cout << "\nThat's wrong. The answer is " << answer;
            cout << "\n";
        }
    }while(choice != 5);
        

    
    return 0;
    


    
}