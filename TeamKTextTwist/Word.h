using namespace System;
using namespace System::Collections::Generic;
#pragma once
namespace model {
ref class Word
{
public:
	Word(void);
	Word(String^ value);

	bool isValid(List<String^>^ dictionary, List<char>^ allowedLetters, bool reuseLetters);
	int getPointValue();
	int getCoinsAwarded();
	bool isInDictionary(List<String^>^);
	String^ Word::getValue();
private:
	bool binarySearch(List<String^>^ wordList, int first, int last);
	int getMidpoint(int first, int last);
	bool containsAllowedCharacters(List<char>^ allowedList);
	bool containsAllowedCharactersReuse(List<char>^ allowedList);
	int getNumberOfOneCoinCharacters();
	int getNumberOfTwoCoinCharacters();
	String^ value;
};
}

