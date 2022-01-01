/*

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void fancy_print(vector<string> r);

int main() {
    // open indicated file
    // get lines making vectors from rules

    string fname = "computergram";
    ifstream file;
    //fname = argv[1]; // filename is first command line argument

    file.open(fname);

    string line;
    int nrules = 0;
    vector<vector<string>> the_rules;
    vector<string> rule;
    size_t i, start, len; // len is number of characters in a category
    string category;

    while (getline(file, line)) {

        i = line.find(" --> "); // i is first after mother
        start = i + 5;          // start is first of daughter
        len = i;                // length of mother is i
        category = line.substr(0, len); // make string from mother

        rule.push_back(category); // mother of rule gets pushed

        /* push all daughters up to last comma */
/*
        while ((i = line.find(",", start)) != string::npos) {
            len = i - start;     // length of current daughter 
            category = line.substr(start, len);
            rule.push_back(category);
            start = i + 1;
        }

        /* push last dtr 

        category = line.substr(start);
        rule.push_back(category);

        /* push the constructed  rule 
        the_rules.push_back(rule);

        nrules++;
        rule.clear();
    }

    
    for (unsigned int i = 0; i < the_rules.size(); i++) {
        fancy_print(the_rules[i]);
    }

    cout << "number of rules was " << the_rules.size() << endl;

    unsigned int num;
    while (true) {
        cout << "rules with how many dtrs?\n";
        cin >> num;
        if (num == 0) { break; }
        for (unsigned int i = 0; i < the_rules.size(); i++) {
            if (the_rules[i].size() == num + 1) {
                fancy_print(the_rules[i]);
            }
        }



    }
}

void fancy_print(vector<string> r) {
    cout << r[0];
    cout << " --> " << endl;
    for (unsigned int i = 1; i < r.size(); i++) {
        cout << "     " << r[i] << endl;
    }

}
*/
