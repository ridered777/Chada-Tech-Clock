#include <iostream>
#include <iomanip> // Allows use of setw
#include <windows.h> // for using Sleep. This will only work on Windows machines.
/*
 * Project 1 - CS 210
 * Author: Craig Harrigan
 * Chada Tech Clock
 */

using namespace std;


int Clock() { //Attempt at a function that allows you to set the clocks time manually. Not used.
    int hours;
    int min;
    int sec;

    cout << "Enter Hours" << endl;
    cin >> hours;
    cout << "Enter Minutes" << endl;
    cin >> min;
    cout << "Enter Seconds" << endl;
    cin >> sec;
    int rawTime = hours*60*60 + min*60 + sec;
    return rawTime; // never found a good way to use this value reliably.
}
int InitializeHours(){ // Initilizes a base value for the clock
    int hours = 20;
    return hours;
}
int InitializeMinutes(){ // Initilizes a base value for the clock
    int minutes = 55;
    return minutes;
}
int InitializeSeconds(){ // Initilizes a base value for the clock
    int seconds = 55;
    return seconds;
}
int FormattedClock(int hours, int min, int sec){
    string amPM;
    int stdHours;
    int input = 0;
    while(input != 4) {

        if (hours >= 12 && hours <= 24) { //Determines if the 12 hour clock should say AM or PM
            amPM = "PM";
        } else {
            amPM = "AM";
        }
        if (hours > 12) {
            stdHours = hours - 12; //format military to standard time
        } else {
            stdHours = hours;
        }
        if (sec > 59) { // Keeps time formatting in base 60
            min += 1;
            sec -= 60;
        }
        if (min > 59) { // Keeps time formatting in base 60
            hours += 1;
            stdHours += 1;
            min -= 60;
        }
        if (hours > 24){ // Goes to new day if clock exceeds 24 hours (not currently tracking/display days)
            hours = 0;
            stdHours = 0;
            // day += 1; Not needed yet
        }

        input = 0; //reset input

        while (input == 0) {
            Sleep(1); // Wait a second and add a second while waiting for the input
            sec += 1;
            // Construct the clock display as shown in the Functionality Document
            cout.fill('0'); //tell cout what to fill with when matching width parameters
            cout << "**************************    **************************" << endl
                 << "*      12-Hour Clock     *    *      24-Hour Clock     *" << endl <<
                 "*      " << setw(2) << stdHours << ":" << setw(2) << min << ":" << setw(2) << sec << " "
                 << amPM << "       *" << "    *      " << setw(2) << hours << ":" << setw(2) <<  min << ":"
                 << setw(2) <<  sec << "          *" << endl
                 << "**************************    **************************"  << endl;
            // Construct the menu display as shows in the Functionality Document
            cout << "**************************" << endl << "* 1 - Add One Hour       *" << endl
                 << "* 2 - Add One Minute     *" << endl << "* 3 - Add One Second     *" << endl
                 << "* 4 - Exit Program       *" << endl << "**************************" << endl;
            cin >> input; // gets the selection
            continue;
        }
        switch (input) { // switch case applies the intended action of the selection
            case 1:
                hours += 1;
                break;
            case 2:
                min += 1;
                break;
            case 3:
                sec += 1;
                break;
            case 4: //Deals with an exit case on first selection
                break;
            default: // Deals with fringe cases using an error message
                cout << "Please enter a valid selection" << endl;
                break;
        }
        continue; // keeps the loop going
    }
    //add the second
    return 0; // exits the program

}
int main() {
    FormattedClock(InitializeHours(), InitializeMinutes(), InitializeSeconds());
}

