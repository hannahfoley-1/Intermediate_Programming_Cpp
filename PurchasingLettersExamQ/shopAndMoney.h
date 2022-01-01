#include <string>
using namespace std;

class Shop {
public:
Shop(string letters, int budget);
string letters;
int budget;
int buy_next_vowel(int paid, char& v, int& change); //cost 10
int buy_next_cons(int paid, char& c, int& change); //cost 3
void report(int status, string type, char letter, int change);
bool purchases_are_Possible(); //enough budget for cheapest available
bool is_vowel(char c);
};

