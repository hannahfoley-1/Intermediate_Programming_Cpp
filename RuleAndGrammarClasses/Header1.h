#pragma once
#include <string>
#include <vector>
using namespace std;

class rule {
public:
    string mother;
    std::vector<string> daughters;
    rule();
    rule r(string line);
    void display();


};