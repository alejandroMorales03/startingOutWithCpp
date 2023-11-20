#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct DivInfo{
    string name;
    short quarter[4];
    float quarterSales[4];
};

void readReport(fstream&, DivInfo[], short size);
void TotalSales(DivInfo[]);
void TotalQuarterSales(DivInfo[]);
void AverageQuarterDivisions(DivInfo[]);
void Extremes(DivInfo[]);



int main(){
    cout << setprecision(2) << fixed;

    fstream  salesReport("report.txt", ios::in|ios::binary);
    if(salesReport.fail()){
        cout << "\nFILE OPENING FAIL\n";
        return 1;
    }
    DivInfo divisions[4];
    cout << sizeof(divisions);
    readReport(salesReport, divisions, sizeof(divisions));
    salesReport.close();
    
    TotalSales(divisions);
    TotalQuarterSales(divisions);
    AverageQuarterDivisions(divisions);
    Extremes(divisions);
    cout << "\n\n";
    
    return 0;
}

void readReport(fstream& report, DivInfo data[], short size){
    report.read(reinterpret_cast<char*>(data), size);
    if(report.fail())
        cout << "\nFILE REPORT READ ERROR\n";
    else
        cout << "\nFILE REPORT READ SUCCESSFULLY\n";
}

void TotalSales(DivInfo div[]){
    float total = 0;
    for(short dix = 0; dix < 4; dix++){
        float div_total = 0;
        for(short index = 0; index < 4; index++){
            div_total += div[dix].quarterSales[index];
        }
        cout << "\nTotal for " << setw(5) << div[dix].name << " division: $ " << setw(10) <<  div_total;
        total+=div_total;
    }
    cout << "\n\nTotal Sales: $ " << setw(23) << total; 

}

void TotalQuarterSales(DivInfo div[]){
    float total;
    cout << "\n";
    for(short index = 0; index < 4; index++){
        total = 0;
        for(short dix = 0; dix < 4; dix++){
            total += div[dix].quarterSales[index];
        }
        cout << "\nTotal Sales for quarter " << index + 1 << ": $ " << setw(9) << total;
    }
}

void AverageQuarterDivisions(DivInfo div[]){
    float total;
    cout << "\n";
    for(short dix = 0; dix < 4; dix++){
        total = 0;
        for(short index = 0; index < 4; index++){
            total += div[dix].quarterSales[index];
        }

        cout << "\nAverage Quarterly Sale for the  " << setw(5) << div[dix].name;
        cout << " division: $ " << setw(10) <<total/4;
    }

}

void Extremes(DivInfo division[]){
    float max = division[0].quarterSales[0] , min = division[0].quarterSales[0] ;
    cout << "\n";
    for(short div = 0; div < 4; div++){
        for(short index = 1; index < 4; index++){
            if(division[div].quarterSales[index] > max)
                max = division[div].quarterSales[index];
            else if(division[div].quarterSales[index] < min)
                min = division[div].quarterSales[index];
        }
    }

    cout << "\nMaximum Quarter Sales: $ " << setw(10) << max;
    cout << "\nMinimum Quarter Sales: $ " << setw(10) << min;
}