#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void fancy_print(vector<string> r);
string getDaughterNoBrackets(string daughter);

int main() {
    // open indicated file
    // get lines making vectors from rules


    string fname = "computergram.txt";
    ifstream file;
    //fname = argv[1]; // filename is first command line argument

    file.open(fname);

    string line;
    //int nrules = 0; commenting out this line because the number of rules will now be the size of 
    //theRules vector
    vector<string> rule;
    vector<vector<string>> theRules;
    size_t i, start, len; // len is number of characters in a category
    string category;

    while (getline(file, line)) {

        i = line.find(" --> "); // i is first after mother
        start = i + 5;          // start is first of daughter
        len = i;                // length of mother is i
        category = line.substr(0, len); // make string from mother

        rule.push_back(category); // mother of rule gets pushed

        /* push all daughters up to last comma */
        while ((i = line.find(",", start)) != string::npos) {
            len = i - start;     // length of current daughter 
            category = line.substr(start, len);
            rule.push_back(category);
            start = i + 1;
        }

        /* push last dtr */

        category = line.substr(start);
        rule.push_back(category);
        theRules.push_back(rule);
        // commentng out these two lines for part 8
        //fancy_print(rule);
        //nrules++;
        rule.clear();
    }

    // commentng out these lines for part 9
    /*
    for (int i = 0; i < theRules.size(); i++)
    {
        fancy_print(theRules[i]);
    }
    cout << "number of rules was " << theRules.size() << endl;
    */

    //now the rules have been processed into a vector of vectors of strings
    //for part 9 i need to repeatedly ask the user to enter a number and then print out all the daughters that have that amount of characters
    bool quit = false;
    int n;

    while (!quit)
    {
        cout << "Enter the number of characters that you want the daughter to have or enter 0 to quit \n";
        cin >> n;
        if (n == 0)
        {
            quit = true;
        }
        else {
            for (int i = 0; i < theRules.size(); i++)
            {
                vector<string> currentRule = theRules[i];
                for (int j = 1; j < currentRule.size(); j++)
                {
                    string currentDaughter = currentRule[j];
                    //cout << currentDaughter  << '\n';
                    currentDaughter = getDaughterNoBrackets(currentDaughter);
                    //cout << currentDaughter << '\n';
                    if (currentDaughter.size() == n)
                    {
                        fancy_print(theRules[i]);
                    }
                }
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

string getDaughterNoBrackets(string daughter)
{
    string noBrackets;
    if (daughter.find('[') == 0)
    {
        int last = daughter.find(']');
        noBrackets = daughter.substr(1, last - 1);
    }
    else
    {
        noBrackets = daughter;
    }
    return noBrackets;
}







