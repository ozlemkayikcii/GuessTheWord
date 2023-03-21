#include "Dictionary.h"                        
#include "Words.h"
#include <iostream>
#include <random>
#include <string>                         
#include <vector>
#include <set>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

int Words::countOfMatchLetters(string word)
{
	int nPebbles = 0;
	for (int i = 0; word[i] != '\0'; i++)
	{
		for (int j = 0; secret[j] != '\0'; j++)
		{
			if (word[i] == secret[j] && word[i] != '0' && secret[j] != '0')
			{
				if (j >= 5 || i >= 5 || word[j] != secret[j])
				{
					nPebbles++;
					word[i] = '0';
					secret[j] = '0';

				}

			}
		}
	}
	return nPebbles;
}
int Words::countOfTruePlaceLetter(string word)
{

	int nRocks = 0;
	for (int i = 0; word[i] != '\0'; i++)
	{
		for (int j = 0; secret[j] != '\0'; j++)
		{
			if (word[i] == secret[j] && word[i] != '0' && secret[j] != '0')
			{
				if (i == j)
				{
					nRocks++;
					word[i] = '0';
					secret[j] = '0';

				}



			}
		}
	}
	return nRocks;
}
Words::Words()
{
	secret = "";
	numguesses = 0;
	cheated = false;
	
};
void Words::playgame(Words &)
{
	
	Dictionary dict("words.txt");
	secret = dict.BringValidWord();
	cout << "Bilbakalim Oyununa Hosgeldiniz:" << endl;
	cout << "5 harften olusan bir kelime tuttum." << endl;
	string guess;
	cout << "Tahmininiz Nedir? ";
	cin >> guess;




	for (int i = 0; i < guess.length(); i++)
	{
		guess[i] = tolower(guess[i]);
	}

	string tempsecret;
	tempsecret = secret;

	while (countOfTruePlaceLetter(guess) != secret.length())
	{
		numguesses += 1;



		if (guess.length() != 5)
		{
			cout << "Harf sayisi yalnizca 5 olmalidir." << endl;
		}
		else
		{

			if (guess == "xxxxx")
			{
				secret = tempsecret;
				cout << "Ipucu: Gizli Kelime: " << secret << endl;
				cheated = true;
			}
			else
			{
				if (!dict.IsWordValid(guess))
				{
					cout << "Bu kelime sozlukte yok!" << endl;
				}

				else
				{



					secret = tempsecret;
					int temp2 = countOfTruePlaceLetter(guess);
					cout << "Eslesen harf sayisi: " << countOfMatchLetters(guess)+ temp2 << endl;
					cout << "Eslesen harflerin dogru konumu: " << temp2 << endl;
					secret = tempsecret;



				}
			}
		}

		cout << "Tahmininiz Nedir? ";
		cin >> guess;
		for (int i = 0; i < guess.length(); i++)
		{
			guess[i] = tolower(guess[i]);
		}
	}
	numguesses += 1;
	if (cheated)
		cout << "Bildiniz! " << numguesses << " tahminde ipucu kullanarak dogru sonuca ulastiniz!" << endl;
	else
		cout << "Bildiniz! " << numguesses << " tahminde dogru sonuca ulastiniz!" << endl;
}

Dictionary::Dictionary(string filename)
{
	ifstream file;
	file.open(filename);
	string line;
	while (getline(file, line))
	{
		words.insert(line);
	}
	set<string>::iterator i;
	for (i = words.begin(); i != words.end(); i++)
	{
		string word = *i;
		if (word.length() == 5)
		{
			secrets.push_back(word);
		}
	}
}
string Dictionary::BringValidWord()
{
	srand(time(0));
	int random_num = (rand() % (secrets.size() - 0 + 1));
	string word = secrets[random_num];

	while (!testLegalSearchWord(word))
	{
		random_num = (rand() % ((secrets.size() - 1) + 1)) + 0;
		word = secrets[random_num];

	}
	return word;
}
bool Dictionary::IsWordValid(string word)
{
	if (words.find(word) == words.end())
	{
		return false;
	}
	return true;
}
bool Dictionary::testLegalSearchWord(string word)
	 {
		 set<char> letters;
		 for (int i = 0; i < word.length(); i++)
		 {
			 if (letters.find(word[i]) != letters.end())
			 {
				 return false;
			 }
			 letters.insert(word[i]);
		 }
		 return true;
	 }
