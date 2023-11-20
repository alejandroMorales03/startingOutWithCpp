#include <iostream>
#include <fstream>

using namespace std;

struct DivInfo{
    string name;
    short quarter[4];
    float quarterSales[4];
};

void populateInfo(DivInfo[]);
void writeReport(fstream&,  DivInfo[], short);

int main(){
    DivInfo divisions[4] = {{"East", {1,2,3,4}},{"West", {1,2,3,4}},{"North", {1,2,3,4}},{"South", {1,2,3,4}}};
    populateInfo(divisions);
    fstream salesReport("report.txt", ios::out|ios::binary);
    if(salesReport.fail()){
        cout << "\nFILE OPEN FAIL\n";
        return 1;
    }
    writeReport(salesReport, divisions, sizeof(divisions));

    salesReport.close();
    return 0;
}

void populateInfo(DivInfo div[]){
    for(short div_i = 0; div_i < 4; div_i++){
        cout << "\nFor the " << div[div_i].name << " division enter: \n\n";

        for(short index = 0; index < 4; index++){
            do{
                cout << "Sales in Quarter " << (index + 1) << ": ";
                cin >> div[div_i].quarterSales[index];
                if(div[div_i].quarterSales[index] < 0)
                    cout << "\nINVALID AMOUNT. AMOUNT MUST BE POSITIVE\n\n";
            }while(div[div_i].quarterSales[index] < 0);
        }
    }
}

void writeReport(fstream& report,  DivInfo data[], short size){
    report.write(reinterpret_cast<char *>(data), size);

    if(report.fail())
        cout << "\nDATA WRITING ERROR\n";
    else
        cout << "\nDATA SUCCESSFULLY WRITTEN TO REPORT\n";

}