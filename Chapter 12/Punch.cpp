#include <iostream>
#include <fstream>

using namespace std;

string getJoke(fstream&);
string getPunch(fstream&);
void generatePunch(fstream&);

int main(){
    fstream punch,joke;
    generatePunch(punch);


    cout << "\n" << getJoke(joke) << "\n";
    cin.get();
    cout << getPunch(punch) << "\n\n";
    joke.close();
    punch.close();
 
    return 0;

}

void generatePunch(fstream& p_file){
    p_file.open("punch.txt", ios::out|ios::app|ios::in);
    if(p_file.fail()){
        cout << "\nFILE NOT FOUND\n\n";
        exit(1);
    }
    p_file << "\nThey make everything up!";
    
}

string getJoke(fstream& j_file){
    j_file.open("joke.txt", ios::in);
    if(j_file.fail()){
        cout << "\nFILE NOT FOUND\n";
        exit(1);
    }
    string joke = "", read;
    while(getline(j_file, read))
        joke += read;
    return joke;
}
string getPunch(fstream& p_file) {
    p_file.seekg(-1L, ios::end);

    while(p_file.get() != '\n')
        p_file.seekg(-2L, ios::cur);

    string punch;
    getline(p_file, punch);
    p_file.clear();
    return punch;
    
}

