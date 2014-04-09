#include "GameController.h"
#include "FileIO.h"

#include <stdlib.h>
#include <time.h>
#include <stdexcept>

namespace model {
GameController::GameController(void)
{

}

int GameController::wordIsContained(vector<string>& wordList, const string& word, int first, int last) {
	if (last < first) {
		return -1;
	}

	int mid = this->getMidpoint(first, last);
	if (wordList[mid] > word) {
		return this->wordIsContained(wordList, word, first, mid - 1);
	} else if (wordList[mid] < word) {
		return this->wordIsContained(wordList, word, mid + 1, last);
	} else {
		return mid;
	}
}

int GameController::getMidpoint(int first, int last) {
	return (first + last) / 2;
}

bool GameController::contains(vector<string>& wordList, const string& word) {
	return this->wordIsContained(wordList, word, 0, wordList.size()-1) == -1;
}

/**
 * Returns the specified number of random letters.
 *
 * @pre totalLetters > 0
 *
 * @return the specified number of random letters.
 */
string GameController::getRandomLetters(int totalLetters) {
	if (totalLetters < 0) {
		invalid_argument("The total letters cannot be negative.");
	}

	vector<char> letters = vector<char>();

	for (int i = 0; i < 11; i++)
	{
		letters.push_back('e');
	}

	for (int i = 0; i < 9; i++)
	{
		letters.push_back('e');
	}

	for (int i = 0; i < 8; i++)
	{
		letters.push_back('o');
	}

	for (int i = 0; i < 6; i++)
	{
		letters.push_back('a');
		letters.push_back('i');
		letters.push_back('n');
		letters.push_back('s');
	}

	for (int i = 0; i < 5; i++)
	{
		letters.push_back('h');
		letters.push_back('r');
	}

	for (int i = 0; i < 4; i++)
	{
		letters.push_back('l');
	}

	for (int i = 0; i < 3; i++)
	{
		letters.push_back('d');
		letters.push_back('u');
		letters.push_back('w');
		letters.push_back('y');
	}

	for (int i = 0; i < 2; i++)
	{
		letters.push_back('b');
		letters.push_back('c');
		letters.push_back('f');
		letters.push_back('g');
		letters.push_back('m');
		letters.push_back('p');
		letters.push_back('v');
	}

	for (int i = 0; i < 1; i++)
	{
		letters.push_back('j');
		letters.push_back('k');
		letters.push_back('q');
		letters.push_back('x');
		letters.push_back('z');
	}

	string randomLetters;
	for (int i = 0; i < totalLetters; i++)
	{
		srand(time(0));
		randomLetters = randomLetters + letters[rand() % letters.size()];
	}

	return randomLetters;
}
}
