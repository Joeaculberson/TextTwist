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

String^ Word::getValue() {
	return this->value;
}

bool Word::containsAllowedCharacters(List<char>^ allowedList) {
	bool allowed = true;
	for (int i = 0; i < this->value->Length; i++) {
		this->processCharacter(i, allowed, allowedList);
	}
	return allowed;
}

void Word::processCharacter(int characterIndex, bool& allowed, List<char>^ allowedList) {
	if (!allowedList->Contains(this->value[characterIndex])) {
		allowed = false;
	} else {
		int index = allowedList->IndexOf(this->value[characterIndex]);
		allowedList[index] = '?';
	}
}

bool Word::containsAllowedCharactersReuse(List<char>^ allowedList) {
	bool allowed = true;
	for (int i = 0; i < this->value->Length; i++) {
		if (!allowedList->Contains(this->value[i])) {
			allowed = false;
		}
	}
	return allowed;
}

bool Word::binarySearch(List<String^>^ wordList, int first, int last) {
	if (first > last) {
		return false;
	}

	int mid = this->getMidpoint(first, last);
	if (wordList[mid] == this->value) {
		return true;
	}
	if (String::Compare(wordList[mid], this->value) > 0) {
		return this->binarySearch(wordList, first, mid - 1);
	} else {
		return this->binarySearch(wordList, mid + 1, last);
	}
}

bool Word::isInDictionary(List<String^>^ wordList) {
	return this->binarySearch(wordList, 0, wordList->Count - 1);
}

int Word::getMidpoint(int first, int last) {
	return (last + first) / 2;
}

bool Word::isValid(List<String^>^ dictionary, List<char>^ allowedLetters, bool reuseLetters) {
	if (reuseLetters) {
		return this->containsAllowedCharactersReuse(allowedLetters) &&  this->isInDictionary(dictionary);
	} else {
		return this->containsAllowedCharacters(allowedLetters) &&  this->isInDictionary(dictionary);
	}
}

int Word::getPointValue() {
	int length = this->value->Length;
	if (length <= 4 ) {
		return 1;
	} else if (length == 5) {
		return 2;
	} else if (length == 6) {
		return 3;
	} else if (length == 7) {
		return 5;
	} else if (length >= 8) {
		return 11;
	} else {
		return -1;
	}
}

int Word::getCoinsAwarded() {
	int coinsAwarded = this->getNumberOfOneCoinCharacters();
	coinsAwarded = coinsAwarded + (this->getNumberOfTwoCoinCharacters() * 2);

	if (this->value->Length >= 8) {
		coinsAwarded = coinsAwarded + 3;
	} else if (this->value->Length >= 5) {
		coinsAwarded = coinsAwarded + 2;
	}

	return coinsAwarded;
}

int Word::getNumberOfTwoCoinCharacters() {
	int numberOfTwoCoinCharacters = 0;
	for (int i = 0; i < this->value->Length; i++) {
		if (this->value[i] == 'q' || this->value[i] == 'z') {
			numberOfTwoCoinCharacters++;
		}
	}

	return numberOfTwoCoinCharacters;
}

int Word::getNumberOfOneCoinCharacters() {
	int numberOfOneCoinCharacters = 0;
	for (int i = 0; i < this->value->Length; i++) {
		if (this->value[i] == 'x' || this->value[i] == 'v') {
			numberOfOneCoinCharacters++;
		}
	}

	return numberOfOneCoinCharacters;
}
}