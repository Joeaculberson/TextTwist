#include "Word.h"
using namespace System::Collections::Generic;

namespace model {

/// <summary>
/// Default constructor for the word class.
/// </summary>
/// <pre>None.</pre>
Word::Word(void)
{
	this->value = "";
}

/// <summary>
/// Constructs a word object with assigned values.
/// </summary>
/// <pre>value != null</pre>
/// <post>value == this->getValue()
/// <param name="value">The value of the string</param>
Word::Word(String^ value)
{
	if (value == nullptr) {
		throw gcnew ArgumentException("value cannot be null");
	}
	this->value = value;
}

/// <summary>
/// Returns the value of the word.
/// </summary>
/// <pre>None.</pre>
/// <returns>The value of the word.</returns>
String^ Word::getValue() {
	return this->value;
}

/// <summary>
/// Returns true if the this word is in the dictionary.
/// </summary>
/// <pre>wordList != null</pre>
/// <param name="wordList">The list of words in the dictionary</param>
/// <returns>True if the word is in the dictionary, false otherwise.</returns>
bool Word::isInDictionary(List<String^>^ wordList) {
	if (wordList == nullptr) {
		throw gcnew ArgumentException("word list cannot be null");
	}
	return this->binarySearch(wordList, 0, wordList->Count - 1);
}

/// <summary>
/// Returns true letters are valid for this word.
/// </summary>
/// <pre>dictionary != nullptr</pre>
/// <pre>allowedLetters != nullptr</pre>
/// <pre>reuseLetters != nullptr</pre>
/// <param name="dictionary">The dictionary to reference.</param>
/// <param name="allowedLetters">The allowed letters to guess from.</param>
/// <param name="reuseLetters">The ability to reuse letters.</param>
/// <returns>True if the word is in the dictionary, false otherwise.</returns>
bool Word::isValid(List<String^>^ dictionary, List<char>^ allowedLetters, bool reuseLetters) {
	if (reuseLetters) {
		return this->containsAllowedCharactersReuse(allowedLetters) &&  this->isInDictionary(dictionary);
	} else {
		return this->containsAllowedCharacters(allowedLetters) &&  this->isInDictionary(dictionary);
	}
}

/// <summary>
/// Returns the point value that the word is worth.
/// </summary>
/// <pre>None</pre>
/// <returns>The word's point value</returns>
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

/// <summary>
/// Returns the coins awarded.
/// </summary>
/// <pre>None.</pre>
/// <returns>The number of coins awarded for this word.</returns>
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

int Word::getMidpoint(int first, int last) {
	return (last + first) / 2;
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
}