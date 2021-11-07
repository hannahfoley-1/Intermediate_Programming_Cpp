#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

bool is_an_email(string s);
bool is_a_top_secret_file(string filename);
vector<string> get_top_secret_emails(string filename);

int main() {

	string filename;
	cout << "which file\n";
	cin >> filename;

	ifstream f;
	f.open(filename);
	if (!f) { cout << "could not open\n"; return 0; }
	
	if (is_a_top_secret_file(filename))
	{
		cout << "Confirmed top-secret file!!! \n";
		cout << "Here are the top-secret emails: \n";
		vector<string> sensitive_information = get_top_secret_emails(filename);
		
		for (int i = 0; i < sensitive_information.size(); i++)
		{
			cout << sensitive_information[i] << '\n';
		}
	}
	else
	{
		cout << "This is not a top-secret file. \n";
	}

	/*
	* MY CODE:
	//checking is an email function
	cout << "Starting email check function";
	string email1 = "hannah@tcd.ie";
	bool email1bool = is_an_email(email1);
	if (email1bool)
	{
		cout << "First test passed as hannah@tcd.ie is a valid email";
	}
	else
	{
		cout << "First test failed ";
	}
	string email2 = "@tcd.iehannah";
	bool emailbool2 = is_an_email(email2);
	if (emailbool2)
	{
		cout << "Second test  failed. ";
	}
	else
	{
		cout << "Second test passed as @tcd.iehannah is not a valid email ";
	}
	string email3 = "hannahtcd.ie@";
	bool email3bool = is_an_email(email3);
	if (emailbool2)
	{
		cout << "Third test failed";
	}
	else
	{
		cout << "Third test passed as @tcd.iehannah is not a valid email ";
	}
	*/

	// DESIRED BEHAVIOUR: if run on top_secret_file should see

	// lisa@simpsons.sit.com
	// joey@friends.sit.com
	// homer@simpsons.sit.com
	// marge@simpsons.sit.com
	// bart@simpsons.sit.com
	// maggie@simpsons.sit.com
	// rachel@friends.sit.com
	// ross@friends.sit.com
	// chandler@friends.sit.com
	// monica@friends.sit.com

}


// COMPLETE THE FUNCTION is_an_email(string s) 
// it should check that
// s contains @ somewhere,
//  but not right at start
//  and not right at end
// ie.
//  amy@blah -> true
//  @blah    -> false
//  blah@    -> false
bool is_an_email(string s) {
	if (s[0] == '@' || s[s.size() - 1] == '@')
	{
		return false;
	}
	else if (s.find('@') != string::npos)
	{
		return true;
	}
	else return false;
}

//This function checks if the file has the string "TOP SECRET"
bool is_a_top_secret_file(string filename)
{
	string fileLine;
	ifstream file;
	file.open(filename);

	while (getline(file, fileLine))
	{
		if (fileLine.find("TOP-SECRET") != string::npos)
		{
			return true;
		}
	}

	return false;
}

// make a vector of all the file's contents and then process that
vector<string> get_top_secret_emails(string filename)
{
	vector<string> emails;
	string word;

	string fileLine;
	ifstream file;
	file.open(filename);

	while (file >> word)
	{
		if (is_an_email(word))
		{
			emails.push_back(word);
		}
	}

	return emails;
}
