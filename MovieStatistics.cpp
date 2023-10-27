#include <iostream>
#include <vector>
using namespace std;

short getStudents();
void getMovies(float*, short);
float findMedian(float array[], short size);
vector<float> findModes(float[], short);

int main(){
    float* ptr = nullptr;
    short size = getStudents();
    ptr = new float[size];
    getMovies(ptr, size);

    cout << "\nThe median is " << findMedian(ptr, size);
    cout << "\nThe mode(s) is/are: ";
    
    vector<float> modes = findModes(ptr, size);
    for(short index = 0; index < modes.size(); index++)
        cout << modes[index] << " ";
    cout << "\n\n";

    delete[] ptr;
    ptr = nullptr; 

    return 0;
}

short getStudents(){
    short students;
    do{
        cout << "\nHow many students were surveyed: ";
        cin >> students;
        if(students < 0)
            cout << "\nINVALID INPUT. MUST BE POSITIVE\n";
    }while(students < 0);
    return students;
}

void getMovies(float* students, short size){
    for(short index = 0; index < size; index++){
        do{
            cout << "\nHow many movies did student " << (index + 1) << " watched: ";
            cin >> *(students + index);
            if(*(students + index) < 0)
                cout << "\nINVALID INPUT. MUST BE POSITIVE\n";
        }while(*(students + index) < 0);
    }
}

float findMedian(float array[], short size){
    float median;

    if(size % 2 != 0)
        median = *(array + (size/2));
    else 
        median = (*(array + size/2) + *(array + size/2 - 1)) / 2.0;

    return median;
}

vector<float> findModes(float array[], short size){
    vector<float>modes(1, -1);
    vector<float>sample(array, array + size);

    short counter = 0, MaxCount = 1;
    float search;

    while(!sample.empty()){
       search = sample[0];
       counter = 0;

       for (int comp = 0; comp < sample.size(); comp++) {
            if (sample[comp] == search) {
                counter++;
            }
        }

       if(counter > 1){
            if(counter == MaxCount)
                modes.push_back(search);
            if(counter > MaxCount){
                modes.clear();
                modes.push_back(search);
                MaxCount = counter;
            }
       }
       sample.erase(remove(sample.begin(), sample.end(), search), sample.end());
    }
    return modes;

}