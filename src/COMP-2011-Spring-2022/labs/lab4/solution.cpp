#include <iostream>
#include <cmath>

using namespace std;
const int NUM_HOUSES = 8;

// Task 3.
void print_houses(int houses[], int cur_pos, int night){
    cout << "Night " << night << ":  " << endl;
    cout << "        ";
    for (int i = 0; i < NUM_HOUSES; i++){
        if (i == cur_pos){
            cout << "| * ";
        }
        else{
            cout << "| " << houses[i] << " ";
        }
    }
    cout << '|' << endl;
}

// Task 2.
int steal_house(int houses[], int cur_pos, int alert_dis, int night){
    int target = (cur_pos + alert_dis) % NUM_HOUSES;
    while(true){
        if (min(abs(cur_pos - target), NUM_HOUSES - abs(cur_pos - target)) < alert_dis){
            return -1;
        }
        if (houses[target] == 0){
            houses[target] = night;
            return target;
        }
        target = (target + 1) % NUM_HOUSES;
    }
}

int main(){ 
    int houses[NUM_HOUSES] = {0};
    int first_target;
    int alert_dis;
    
    cout << endl << "The number of houses in this community is " << NUM_HOUSES << "." << endl;
    // input the first target house ID of the thief (current position) and 
    // the alert distance (min interval) of the security system.
    cout << "Please input the first target house ID of the thief: " << endl;
    cin >> first_target;
    while ((first_target >= NUM_HOUSES) || (first_target < 0)){
        cout << "The target of the thief should less than " << NUM_HOUSES << endl;
        cout << "Please re-input the first target ID: " << endl;
        cin >> first_target;
    }
    houses[first_target] = 1;  // Set first target to 1

    cout << "Please input the alert distance of the community's security system: " << endl;
    cin >> alert_dis;
    while ((alert_dis >= NUM_HOUSES) || (alert_dis < 0)){
        cout << "The alert distance of the community's security system should less than " << NUM_HOUSES << endl;
        cout << "Please re-input the alert distance: " << endl;
        cin >> alert_dis;
    }
    cout << endl;

    int cur_pos = first_target;
    int night = 1;
    print_houses(houses, cur_pos, night);
    while(true){
        // Task 1.
        night++;
        cur_pos = steal_house(houses, cur_pos, alert_dis, night);
        if (cur_pos >= 0){
            print_houses(houses, cur_pos, night);
        }
        else{
            break;
        }
    }
    cout << endl << "No house can be stolen." << endl << "Finished." << endl;
}