#include <iostream>
#include <string>
using namespace std;

//defining the two functions that will be written below
bool is_vowel(char c);
bool is_cons(char c);

  bool is_vowel(char c){
  switch(c){
  case 'a':
    return true;
  case 'e':
    return true;
  case 'i':
    return true;
  case 'o':
    return true;
  case 'u':
    return true;
  default:
    return false;
  }
}

bool is_cons(char c){
  if (is_vowel(c))
    {
      return false;
    }
  else if (c >= 97 && c <= 122) //ascii codes for all alphabet, whats left are constants
    {
      return true;
    }
  else //if any other character eg space, number, question mark
    {
      return false;
    }
}


  
