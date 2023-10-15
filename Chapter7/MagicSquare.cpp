#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

short Populator(short[][3]);
bool checkRows(short[][3], short);
bool checkColumns(short[][3], short);
bool checkDiagonals(short[][3], short);

int main(){

    short grid[3][3];
    short startingPoint = Populator(grid);

    if(checkRows(grid, startingPoint) && checkColumns(grid, startingPoint) && checkDiagonals(grid, startingPoint))
        cout << "\nLO SHU MAGIC SQUARE\n\n";
    else
        cout <<  "\nNO LO SHU MAGIC SQUARE\n\n";
    
    return 0;
}

/**
 * @brief Populates a 3 by 3 array with numbers between 1 and 9
 * 
 * @param chart 
 */
short Populator(short chart[][3]){
    srand(time(0));
    short row_one = 0;
    for(short row = 0; row < 3; row++){
        for(short col = 0; col < 3; col++){
            chart[row][col] = (rand() % (9 - 1 + 1) + 1);
            cout << chart[row][col] << " ";
            if(row == 0)
                row_one += chart[row][col];
        }
        cout << "\n";
    }
    return row_one;
}

/**
 * @brief Checks the sum of rows to see if they match a value. If they do not the loop ends.
 * 
 * @param chart 
 * @param checkValue 
 * @return true 
 * @return false 
 */
bool checkRows(short chart[][3], short checkValue){
    bool valid = true;

    for(short row = 1; row < 3 && valid; row++){
        short row_total = 0;
        for(short col = 0; col < 3; col++){
            row_total += chart[row][col];
        }
        if(row_total != checkValue)
            valid = false;
    }
    return valid;
}

/**
 * @brief Checks the sum of columns to see if they match a value. If they do not the loop ends.
 * 
 * @param chart 
 * @param checkValue 
 * @return true 
 * @return false 
 */
bool checkColumns(short chart[][3], short checkValue){
    bool valid = true;

    for(short col = 0; col < 3 && valid; col++){
        short col_total = 0;
        for(short row = 0; row < 3; row++){
            col_total += chart[row][col];
        }
        if(col_total != checkValue)
            valid = false;
    }
    return valid;
}

/**
 * @brief Checks the sum of the diagonals to see if they match a value. If they do not the loop ends.
 * 
 * @param chart 
 * @param checkValue 
 * @return true 
 * @return false 
 */
bool checkDiagonals(short chart[][3], short checkValue){
    bool valid = true;
    short total = 0;
    for(short row = 0; row < 3; row++){
        total += chart[row][row];
    }
    if(total != checkValue)
        valid = false;

    total = 0;
    for(short row  = 0, col = 2; valid && row < 3 && col >= 0; col--, row++){
        total += chart[row][col]; 
    }

    if(total != checkValue)
        valid = false;

    return valid;
}

