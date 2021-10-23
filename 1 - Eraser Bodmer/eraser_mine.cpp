#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//defining the functions that will be used in this program
bool is_vowel(char c);
bool is_cons(char c);

int main(){
  fstream thefile;
  thefile.open("afile_from_bodmer");

  cout << "Would you like to elimainate vowels or constants? Enter 1 for vowels and 2 for constants. \n ";
  int choice;
  cin >> choice;

  string s;
  string erased;
  while(getline(thefile, s)){
    for(int i=0; i<s.size(); i++){
      char c = s[i];
      if(choice == 1){
	if(is_vowel(c)){
	  erased +='*';
	}
	else{
	  erased += c;
	}
      }
      if(choice == 2){
	if(is_cons(c)){
	  erased += '*';
	}
	else{
	  erased += c;
	}
      }
    }
  }
  cout << erased << '\n' << endl ;
}

