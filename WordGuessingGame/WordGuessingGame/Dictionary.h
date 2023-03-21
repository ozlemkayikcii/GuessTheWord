#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
                           // Ozlem Kayikci  152120191043

using namespace std;

class Dictionary
{
public:
	Dictionary() {};
	Dictionary(string);
	string BringValidWord();
	bool IsWordValid(string );
	~Dictionary() {};
private:
	set<string> words;
	vector<string> secrets;
	bool testLegalSearchWord(string);
}; 
#endif