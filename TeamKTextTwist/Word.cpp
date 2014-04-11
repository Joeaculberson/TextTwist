#include "Word.h"
using namespace System::Collections::Generic;

namespace model {
Word::Word(void)
{
	this->value = "";
}

Word::Word(String^ value)
{
	this->value = value;
}

bool Word::containsAllowedCharacters(List<char>^ allowedList) {
	bool allowed = true;
	for (int i = 0; i < this->value->Length; i++) {
		if (!allowedList->Contains(this->value[i])) {
			allowed = false;
		} else {
			int index = allowedList->IndexOf(this->value[i]);
			allowedList[index] = '?';
		}
	}

	return allowed;
}

int Word::binarySearch(List<String^>^ wordList, int first, int last) {
	return false;
}

bool Word::isInDictionary(List<String^>^ wordList) {
	return this->binarySearch(wordList, 0, wordList->Count - 1);
}

int Word::getMidpoint(int first, int last) {
	return (first + (last - first)) / 2;
}

bool Word::isValid(List<String^>^ dictionary, List<char>^ allowedLetters) {
	return this->containsAllowedCharacters(allowedLetters) /*&& this->isInDictionary(dictionary)*/;
}
}