// whileLoopIntDivision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

int main() {

    int fahr, celsius;
    int lower, upper, step;

    lower = 0;     /* lower limit of temperature table */
    upper = 300;   /* upper limit */
    step = 20;     /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        cout << fahr << '\t' << celsius << '\n';
        fahr = fahr + step;
    }
}