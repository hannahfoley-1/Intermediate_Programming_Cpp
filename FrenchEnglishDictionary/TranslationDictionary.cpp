/************* TranslationDictionary.cpp **********************/
#include <string>
#include <iostream>
#include <fstream>


#include "TranslationDictionary.h"

using namespace std;

Trans_Dict::Trans_Dict() {}

/*************************************************************************/
/* builds dictionary from file with translation pairs source/translation */
/* on single lines                                                       */
/*************************************************************************/
Trans_Dict::Trans_Dict(string file_name) {
    string line, translation, word;
    ifstream f;
    Transpair p;
    size_t trans_offset;


    f.open(file_name);
    if (f) {
        opened_ok = true;
    }
    else {
        opened_ok = false;
    }

    if (opened_ok) {

        while (f >> line) {
            trans_offset = line.find('/'); /* trans_offset is location of / */

            if (trans_offset == string::npos) {
                cout << "there was an entry with no /\n";
                continue;
            }
            else {
                word = line.substr(0, trans_offset); // up to / 
                translation = line.substr(trans_offset + 1); // after / 
                // make transpair with word and translation
                p.french = word;
                p.english = translation;
                thewords.push_back(p); // add transpair to thewords
            }

        }
    }

}


/*****************************************************************/
/* looks up word in dictionary, returning true or false          */
/* setting 'trans' to contain the translation if found           */
/*****************************************************************/
bool Trans_Dict::lookup(string word, string& trans) {
    int i;
    for (i = 0; i < thewords.size(); i++) {
        if (thewords[i].french == word) {
            trans = thewords[i].english;
            return true;
        }
    }
    return false;
}

/******************************************************************
Part 2 : Add a function to the class which takes an english word 
         and tells you the equivalent french word
******************************************************************/
bool Trans_Dict::returnFrenchFor(string english, string& trans) {
    for (int i = 0; i < thewords.size(); i++) {
        if (thewords[i].english == english)
        {
            trans = thewords[i].french;
            return true;
        }
    }
    return false;
}

/******************************************************************
Part 3 : Add a function update(string french, string english) which
adds/updates the dictionary entry for the indicated french word.
Note the intention is that the vector thewords should get updated 
and not the file from which the dictionary was constructed.
******************************************************************/
void Trans_Dict::update(string french, string english) {
    bool updated = false;
    for (int i = 0; i < thewords.size(); i++)
    {
        while (!updated)
        {
            if (thewords[i].french == french)
            {
                /*The french word has been found so its english translation should be changed to match
                english */
                thewords[i].english = english;
                updated = true;
            }
            else
            {
                /*The french word has not been found so the dictionary should be updated*/
                Transpair newWord;
                newWord.french = french;
                newWord.english = english;
                thewords.push_back(newWord);
                updated = true;
            }
        }

    }
}

/******************************************************************
Part 4 : Add a function export_to_file(string filename) which will 
create a file representing the contents of the dictionary's thewords
vector. The file should have the same format as the word-list files
which are given to the constructor of the class.
******************************************************************/
void Trans_Dict::export_to_file(string filename)
{
    fstream file(filename);

    for (int i = 0; i < thewords.size(); i++)
    {
        file << thewords[i].french << "/" << thewords[i].english << '\n';
    }

    file.close();
}





