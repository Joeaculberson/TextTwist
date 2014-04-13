#pragma once

#include "FileIO.h"
#include "Word.h"
using namespace System::Collections::Generic;
using namespace System;
using namespace model;

namespace model {
ref class GameController
{
private:
	List<String^>^ wordList;
	FileIO^ fileIO;
	Player^ player;
public:
	GameController();

	String^ getRandomLetters(int totalLetters);
	String^ shuffleLetters(String^ lettersToShuffle);
	void setPlayerName(String^ name);
	void incrementPlayerScore(int number);
	void decrementPlayerScore();
	void createNewPlayer();
	List<char>^ stringToChars(String^ toConvert);
	bool isWordValid(Word^ word, String^ allowedLetters);
	String^ getPlayerScoreString();
};
}