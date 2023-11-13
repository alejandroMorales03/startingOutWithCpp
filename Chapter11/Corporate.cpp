#include <iostream>
using namespace std;

struct DivisionInfo{
    string name;
    double fq_sales;
    double sq_sales;
    double tq_sales;
    double foq_sales;
    double total_sales;
    double av_sales;
    
};

void getSales(DivisionInfo&);
void printInfo(const DivisionInfo&);
bool validateInput(double, double = 0);

int main(){
    DivisionInfo Divisions[4] = {{"East"},{"West"},{"North"},{"South"}};
    for(short index = 0; index < sizeof(Divisions)/sizeof(Divisions[0]); index++){
        getSales(Divisions[index]);
    }

    for(DivisionInfo div : Divisions){
        cout << "\nDiv Name: " << div.name;
        cout << "\nFirst Quarter Sales:  $ " << div.fq_sales;
        cout << "\nSecond Quarter Sales: $ " << div.sq_sales;
        cout << "\nThird Quarter Sales:  $ " << div.tq_sales;
        cout << "\nFourth Quarter Sales: $ " << div.foq_sales; 
        cout << "\nTotal Sales:          $ " << div.total_sales;
        cout << "\nAverage Sales:        $ " << div.av_sales;
        cout << "\n";
    }
    cout << "\n";
    return 0;

}

void getSales(DivisionInfo& div){
    cout << "\nFor the " << div.name << " division enter: \n\n";
    
    do{
        cout << "First Quarter Sales $: ";
        cin >> div.fq_sales;
    }while(!validateInput(div.fq_sales));
    div.total_sales += div.fq_sales;

    do{
        cout << "Second Quarter Sales $: ";
        cin >> div.sq_sales;
    }while(!validateInput(div.sq_sales));

    div.total_sales += div.sq_sales;

    do{
        cout << "Third Quarter Sales $: ";
        cin >> div.tq_sales;
    }while(!validateInput(div.tq_sales));
    div.total_sales += div.tq_sales;

    do{
        cout << "Fourth Quarter Sales: $: ";
        cin >> div.foq_sales;
    }while(!validateInput(div.foq_sales));
    div.total_sales += div.foq_sales;

    div.av_sales = div.total_sales / 4;

}

void printInfo(const DivisionInfo& div){
    cout << "\nDiv Name: " << div.name;
    cout << "\nFirst Quarter Sales: $ " << div.fq_sales;
    cout << "\nSecond Quarter Sales: $ " << div.sq_sales;
    cout << "\nThird Quarter Sales: $ " << div.tq_sales;
    cout << "\nFourth Quarter Sales: $ " << div.foq_sales; 
    cout << "\nTotal Sales: $ " << div.total_sales;
    cout << "\nAverage Sales: $ " << div.av_sales;
    cout << "\n";
}

bool validateInput(double input, double lower_bound){
    if(input < lower_bound){
        cout << "\nERROR! NEGATIVE SALES ARE NOT VALID\n\n";
        return false;
    }
    return true;
}