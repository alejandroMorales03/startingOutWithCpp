#include <iostream>
#include <iomanip>
using namespace std;

struct Player{
    string name;
    short number;
    short points;
};
const short NUM_PLAYERS = 12;


void populateTeamInfo(Player[]);
bool validatePlayerNumber(Player[], Player, short);
short getBestWidth(Player[]);
void printTeamInfo(Player[]);
short getTotalPoints(Player[]);
Player findBestPlayer(Player[]);

int main(){
    Player team[NUM_PLAYERS];
    populateTeamInfo(team);
    printTeamInfo(team);
    cout << "\nTotal Points Scored by the Team: " << getTotalPoints(team);

    Player bestPlayer = findBestPlayer(team);
    cout << "\nBest Player: " << bestPlayer.name << ", " << bestPlayer.points << " points\n\n";

    return 0;
}

void populateTeamInfo(Player team_arg[]){
    for(short index = 0; index < NUM_PLAYERS; index++){
        cout << "\nEnter player's name: ";
        getline(cin, team_arg[index].name);

        do{
            cout << "Enter " << team_arg[index].name << "'s number: ";
            cin >> team_arg[index].number;
            if(team_arg[index].number < 1)
                cout << "\nINVALID PLAYER NUMBER\n\n";
        }while(team_arg[index].number < 1 || validatePlayerNumber(team_arg, team_arg[index], index));

        do{
            cout << "Enter player's scored points: ";
            cin >> team_arg[index].points;
            if(team_arg[index].points < 0)
                cout << "\nINVALID SCORE\n";
        }while(team_arg[index].points < 0);
        cin.ignore();

    }
}
short getBestWidth(Player team_arg[]){
    short ideal_width = 0;
    for(short index = 0; index < NUM_PLAYERS; index++){
        if(team_arg[index].name.length() > ideal_width)
            ideal_width =  team_arg[index].name.length();
    }
    return ideal_width;
}

void printTeamInfo(Player team_arg[]){
    short width = getBestWidth(team_arg);
    cout << "\n" << setw(width) << "Name" << "\tNumber\tPoints\n";
    for(short index = 0; index < NUM_PLAYERS; index++){
        cout << setw(width) << team_arg[index].name << "\t";
        cout << setw(6) << right << team_arg[index].number << "\t";
        cout << setw(6) << right << team_arg[index].points << "\n";
    }
}

bool validatePlayerNumber(Player team[], Player player, short player_index){
    bool number_is_taken = false;
    string numberOwner = "";

    for(short index = 0; index < player_index && !number_is_taken; index++){
        if(team[index].number == player.number){
            number_is_taken = true;
            numberOwner = team[index].name;
        }
    }

    if(number_is_taken)
        cout << "\nThat number belongs to " << numberOwner <<  "\n\n";

    return number_is_taken;

}

short getTotalPoints(Player team_arg[]){
    short total = 0;
    for(short index = 0; index < NUM_PLAYERS; index++)
        total += team_arg[index].points;

    return total;
}

Player findBestPlayer(Player team[]){
    Player bestPlayer;
    bestPlayer.points = team[0].points;
    bestPlayer.name = team[0].name;
    bestPlayer.number = team[0].number;

    for(short index = 1; index < NUM_PLAYERS; index++){

        if(team[index].points > bestPlayer.points){
            bestPlayer.points = team[index].points;
            bestPlayer.name = team[index].name;
            bestPlayer.number = team[index].number;
        }
        
    }
    return bestPlayer;
}