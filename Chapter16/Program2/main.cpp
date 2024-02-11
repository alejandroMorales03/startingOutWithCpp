#include "/Users/alejandromorales/projects/Chapter16/Program2/MilTimeObj/MilTime.h"
using namespace std;

//Code is tested and fully operational
int main(){

    try{
        unique_ptr<Time> militaryTimeTest(new MilTime(2340, 30));
        std::cout << militaryTimeTest->getTime();
        std::cout << " " << militaryTimeTest->getTimeSetting() << "\n\n";
        

    }catch(Time::InvalidTimeSetting e){
        std::cout << "\nERROR: TIME SETTING " << e.excp_setting << " IS INAPPROPRIATE FOR " << e.excp_hour << " HOUR.\n";
    }catch(Time::BadHour e){
        std::cout << "\nERROR: HOUR ARGUMENT " << e.excp_hour << " IS OUT OF RANGE [0 - 23]\n";
    }catch(Time::BadMinute e){
        std::cout << "\nERROR: MINUTE ARGUMENT " << e.excp_min << " IS OUT OF RANGE [0 - 59]\n";
    }catch(Time::BadSecond e){
        std::cout << "\nERROR: SECOND ARGUMENT " << e.excp_second << " IS OUT OF RANGE [0 - 59]\n";
    }
    

    
    return 0;
}