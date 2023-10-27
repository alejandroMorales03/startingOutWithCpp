#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
vector<float> findModes(float[], short);
float* getSample();


int main(){
    float* sample = getSample();
    vector<float> modes = findModes(sample, 10);
    cout << "\n\nMODE(S)\n\n";
    if(modes.empty())  
        cout << "\nThere is no mode";
    else{
        for(float x : modes)
            cout << x << " ";

        cout << "\n\n";
    }

    delete[] sample;
    sample = nullptr;

    

    return 0;
}

/**
 * @brief Finds the mode(s) in a given arry
 * 
 * @param array 
 * @param size 
 * @return vector<float> 
 */
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

/**
 * @brief Get the Sample object
 * 
 * @return float* 
 */
float* getSample(){
    float* array = new float[10];
    srand(time(0));
    cout << "\n";
    for(short count = 1; count <= 10; count++){
        array[count - 1] = (rand() % (20 - 0 + 1) + 0);
        cout << array[count - 1] << " ";
    }
    return array;
}



