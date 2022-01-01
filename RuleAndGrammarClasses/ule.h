#pragma once
#include <string>
#include <vector>
using namespace std;

class Rule {
public:
    string mother;
    std::vector<string> daughters;
    Rule();
    Rule r(string line);
    void display();


};