#include "shopAndMoney.h"

Shop::Shop(string letters, int budget)
{
	this->letters = letters;
	this->budget = budget;
}

int Shop::buy_next_vowel(int paid, char& v, int& change) {
	if (paid > budget)
	{
		return 1;
	}
	if (paid < 10)
	{
		return 2;
	}
	bool vowelFound = false;
	for (int i = 0; i < letters.size() && !vowelFound; i++)
	{
		if (is_vowel(letters[i]))
		{
			vowelFound = true;
			char vowelBought = letters[i];
			v = vowelBought;
			letters[i] = '/';
			int changeDue = paid - 3;
			change = changeDue;
			budget -= 10;
			return 0;
		}
	}
	return 3;
}

int Shop::buy_next_cons(int paid, char& v, int& change) {
	if (paid > budget)
	{
		return 1;
	}
	if (paid < 3)
	{
		return 2;
	}
	bool consFound = false;
	for (int i = 0; i < letters.size() && !consFound; i++)
	{
		if (!is_vowel(letters[i]) && letters[i] != '/')
		{
			consFound = true;
			char consBought = letters[i];
			v = consBought;
			letters[i] = '/';
			int changeDue = paid - 3;
			change = changeDue;
			budget -= 3;
			return 0;
		}
	}
	return 3;
}

bool Shop::purchases_are_Possible() {
	bool cons = false;
	int maxPrice;
	int lettersLeft = letters.size();
	for (int pos = 0; pos < letters.size(); pos++)
	{
		while (!cons && lettersLeft > 0)
		{
			if (!is_vowel(letters[pos]))
			{
				if (letters[pos] == '/')
				{
					lettersLeft--;
				}
				cons = true;
				pos = letters.size();
			}
		}
		if (lettersLeft == 0)
		{
			return false;
		}
	}
	if (cons)
	{
		maxPrice = 3;
	}
	else {
		maxPrice = 10;
	}
	if (budget >= maxPrice) {
		return true;
	}
	else
	{
		return false;
	}
}

bool Shop::is_vowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		return true;
	}
	return false;
}
