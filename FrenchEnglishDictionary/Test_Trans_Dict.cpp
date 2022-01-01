/*********************************/
/* tests the Trans_Dict class    */
/*********************************/
#include <iostream>
#include "TranslationDictionary.h"
#include <stdlib.h>

using namespace std;

void tester_function(Trans_Dict& d, string name, vector<string> fr_words);


int main() {
    Trans_Dict d1("translist.txt");
    Trans_Dict d2("translist2.txt");

    if (!d1.opened_ok) {
        cerr << "dictionary to translist did not open ok\n";
        exit(0);
    }

    if (!d2.opened_ok) {
        cerr << "dictionary to translist2 did not open ok\n";
        exit(0);
    }

    /*****************************
    * Test for functions I added 
    * incl. those required in brief
    * ***************************/
    string shoe = "shoe";
    string trans;
    if (d1.returnFrenchFor(shoe, trans))
    {
        cout << "The French for shoe is " << trans << '\n';
    }
    else
    {
        cout << "no translist trans of shoe";
    }
   
    string dog = "dog";
    if (d2.returnFrenchFor(dog, trans))
    {
        cout << "The French for dog is " << trans << '\n';
    }
    else
    {
        cout << "no translist2 trans of dog";
    }

    if (d2.returnFrenchFor("hat", trans))
    {
        cout << "The French for hat is " << trans << '\n';
    }
    else
    {
        cout << "no translist2 trans of hat \n";
    }

    string hello = "Hello";
    string bonjour = "Bonjour";
    d1.update(bonjour, hello);
    d1.returnFrenchFor(hello, trans);
    cout << "The French for hello is " << trans << '\n';
    if (d1.lookup(bonjour, trans))
    {
        cout << "translist trans of bonjour is " << trans << '\n';
    }

    d1.export_to_file("TextFile3.txt");

    d1.update("chapeau", "hat");
    cout << "Testing d1 after adding chapeau\hat \n";
    if (d1.lookup("chapeau", trans))
    {
        cout << "The translist trans of chapeau is " << trans << '\n';
    }
    else
    {
        cout << "no translist trans of chapeau \n";
    }

    d2.update("chien", "hound");
    cout << "test d2 after adding chien/hound \n";
    if (d2.returnFrenchFor("hound", trans))
    {
        cout << "The French for hound is " << trans << '\n';
    }
    else
    {
        cout << "no translist trans of hound";
    }


    //The tests that existed in this file already
    string trans_english;

    if (d1.lookup("soulier", trans_english)) {
        cout << "translist trans of soulier is " << trans_english << '\n';
    }
    else {
        cout << "no translist trans of soulier\n";
    }

    if (d1.lookup("jupe", trans_english)) {
        cout << "translist trans of jupe is " << trans_english << '\n';
    }
    else {
        cout << "no translist trans of jupe\n";
    }

    if (d1.lookup("chien", trans_english)) {
        cout << "translist trans of chien is " << trans_english << '\n';
    }
    else {
        cout << "no translist trans of chien\n";
    }


    if (d2.lookup("chien", trans_english)) {
        cout << "translist2 trans of chien is " << trans_english << '\n';
    }
    else {
        cout << "no translist2 trans of chien\n";
    }


    if (d2.lookup("oiseau", trans_english)) {
        cout << "translist2 trans of oiseau is " << trans_english << '\n';
    }
    else {
        cout << "no translist2 trans of oiseau\n";
    }

    if (d2.lookup("soulier", trans_english)) {
        cout << "translist2 trans of soulier is " << trans_english << '\n';
    }
    else {
        cout << "no translist2 trans of soulier\n";
    }

    



    /* you could replace the above series of tests with the following
       more economical code which use a function to run the tests

     */
     // fr_words = {"soulier", "jupe", "chien"};
     // tester_function(d1, "translist", fr_words);
     // fr_words = {"chien", "oiseau", "soulier"};
     // tester_function(d2, "translist2", fr_words);

}

void tester_function(Trans_Dict& d, string name, vector<string> fr_words) {
    string trans_english;
    bool found;
    for (unsigned int i = 0; i < fr_words.size(); i++) {
        if (d.lookup(fr_words[i], trans_english)) {
            cout << name << " trans of " << fr_words[i] << " is " << trans_english << endl;
        }
        else {
            cout << "no " << name << " trans of " << fr_words[i] << endl;
        }
    }
}