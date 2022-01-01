#include "Grammar.h"
#include <iostream>
#include <fstream>

Grammar::Grammar() {}

// open the file, get its lines one-by-one, feeding these to Rule constructor
// and using to build up rules member
Grammar::Grammar(string fname) {
    ifstream file;

    file.open(fname);

    string line;

    while (getline(file, line)) {
        Rule newRule = newRule.r(line);
        rules.push_back(newRule);
    }
}

// go thru rules using each members show method
void Grammar::show() {
    for (int i = 0; i < rules.size(); i++)
    {
        rules[i].display();
    }
}