#include <iostream>

using namespace std;
bool lengthCheck(string);
bool digitCheck(string);
bool upperCheck(string);
bool lowerCheck(string);
void passValidation(string);

int main(){
    string password;
    cout << "\nEnter your password: ";
    getline(cin, password);
    passValidation(password);
    return 0;

}

bool lengthCheck(string pass_w){
    if(pass_w.length() >= 6)
        return true;
    cout << "\n* PASSWORD MUST BE AT LEAST 6 CHARACTERS LONG";
    return false;
}

bool digitCheck(string pass_w){
    for(char key : pass_w){
        if(isdigit(key))
            return true;
    }
    cout << "\n* AT LEAST ONE CHARACTER MUST BE A DIGIT";
    return false;
}

bool upperCheck(string pass_w){
    for(char key : pass_w){
        if(isupper(key))
            return true;
    }
    cout << "\n* AT LEAST ONE CHARACTER MUST BE UPPERCASE";
    return false;
}

bool lowerCheck(string pass_w){
    for(char key : pass_w){
        if(islower(key))
            return true;
    }
    cout << "\n* AT LEAST ONE CHARACTER MUST BE LOWERCASE";
    return false;
}

void passValidation(string pass_w){
    if(lengthCheck(pass_w) && digitCheck(pass_w) && upperCheck(pass_w) && lowerCheck(pass_w)){
        cout << "\nVALID PASSWORD\n\n";
    }
    else{
        cout << "\n\nYOU WILL NEED ANOTHER PASSWORD\n\n";
    }
}

