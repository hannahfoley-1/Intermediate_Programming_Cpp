#include "Rule.h"
#include <string>
#include <iostream>

using namespace std;

Rule::Rule() {}

Rule Rule::r(string line) {
    size_t i, start, len; // len is number of characters in a category
    string category;
    Rule newRule;
    i = line.find(" --> "); // i is first after mother
    start = i + 5;          // start is first of daughter
    len = i;                // length of mother is i
    category = line.substr(0, len); // make string from mother

    newRule.mother = category;

    while ((i = line.find(",", start)) != string::npos) {
        len = i - start;     // length of current daughter 
        category = line.substr(start, len);
        newRule.daughters.push_back(category);
        //line now equals to remainder of string
        line = line.substr(start + len);
        start = 1;
    }
    newRule.daughters.push_back(line.substr(start));

    return newRule;
}

void Rule::display()
{
    cout << mother;
    cout << " --> " << endl;
    for (int i = 0; i < daughters.size(); i++)
    {
        cout << "   " << daughters[i] << '\n';
    }

}