#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "FileIO.h"
using namespace std;

namespace model {
ref class GameController
{
private:
	int getMidpoint(int first, int last);
public:
	GameController(void);

	int wordIsContained(vector<string> wordList, const string& word, int first, int last);
	bool contains(vector<string> wordList, const string& word);
};
}