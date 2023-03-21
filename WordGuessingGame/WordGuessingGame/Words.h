#ifndef WORDS_H
#define WORDS_H
#include <iostream>
#include <string>


using namespace std;               // Ozlem Kayikci  152120191043

class Words {
private:
	string secret;
	int numguesses;
	bool cheated;
	int countOfMatchLetters(string );
	int countOfTruePlaceLetter(string );
public:
	Words();
	void playgame(Words &);
	~Words() {};
};
#endif