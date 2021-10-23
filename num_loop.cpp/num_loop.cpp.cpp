#include <iostream>
using namespace std;

// here is a possible answer
// note use of while(1) loop with a break to get out of it
// also the sequential && prevents division by 0
int main() {

    float total = 0;
    float number;
    while (true) {
        cout << "enter a number:";
        cin >> number;
        if ((total != 0) && (number / total < 1.0 / 10)) {
            cout << "your contribution is so derisory that I am exiting my loop\n";
            break;
        }
        else {
            total = total + number;
            cout << "running total is: " << total << endl;
        }

    }

}