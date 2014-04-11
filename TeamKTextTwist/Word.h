using namespace System;
using namespace System::Collections::Generic;
#pragma once
namespace model {
ref class Word
{
public:
	Word(void);
	Word(String^ value);

	bool isValid(List<String^>^ dictionary, List<char>^ allowedLetters);
private:
	int binarySearch(List<String^>^ wordList, int first, int last);
	int getMidpoint(int first, int last);
	bool isInDictionary(List<String^>^);
	bool containsAllowedCharacters(List<char>^ allowedList);
	String^ value;
};
}

