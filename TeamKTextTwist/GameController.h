#pragma once

#include "FileIO.h"
using namespace System::Collections::Generic;
using namespace System;
using namespace model;

namespace model {
ref class GameController
{
private:
	List<String^>^ wordList;
	FileIO^ fileIO;

	int getMidpoint(int first, int last);
	int binarySearchWord(String^ word, int first, int last);
	List<char>^ stringToChars(String^ word);
public:
	GameController();

	bool contains(String^ word);
	String^ getRandomLetters(int totalLetters);
	String^ shuffleLetters(String^ lettersToShuffle);
	
};
}