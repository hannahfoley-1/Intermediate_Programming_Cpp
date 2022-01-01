#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Rule.h"
#include "Grammar.h"

using namespace std;

int main() {
    string fname = "computergram.txt";
    ifstream file;

    file.open(fname);

    string line;

    vector<Rule> rules;

    cout << "First testing creating the rules using the rule class and functions \n";
    while (getline(file, line)) {
        Rule newRule = newRule.r(line);
        rules.push_back(newRule);
    }

    for (int i = 0; i < rules.size(); i++)
    {
        rules[i].display();
    }

    cout << "Number of rules was " << rules.size() << '\n';

    cout << "Now testing a rule for whether it contains a specific number of daughters, which should be easier now we have the rule class \n";

    bool quit = false;
    int num;
    while (!quit) {
        cout << "rules with how many dtrs? Or enter 0 to quit (and move on to see grammar class working)";
        cin >> num;
        if (num == 0) {
            break;
        }
        for (unsigned int i = 0; i < rules.size(); i++) {
            if (rules[i].daughters.size() == num) {
                rules[i].display();
            }
        }
    }

    cout << "Now testing using the Grammar class \n";
    Grammar grammar = Grammar("computergram.txt");
    grammar.show();
}