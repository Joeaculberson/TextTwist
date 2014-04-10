#include "GameController.h"
#include "FileIO.h"
#include <iostream>

using namespace System::Text;

namespace model {
GameController::GameController()
{
	this->fileIO = gcnew FileIO();
	this->wordList = this->fileIO->parseFile();
	this->player = gcnew Player();
}

int GameController::binarySearchWord(String^ word, int first, int last) {
	if (last < first) {
		return -1;
	}

	int mid = this->getMidpoint(first, last);
	if (String::Compare(this->wordList[mid], word) > 1) {
		return this->binarySearchWord(word, first, mid - 1);
	} else if (String::Compare(this->wordList[mid], word) < 1) {
		return this->binarySearchWord(word, mid + 1, last);
	} else {
		return mid;
	}
}

int GameController::getMidpoint(int first, int last) {
	return (first + (last - first)) / 2;
}

bool GameController::contains(String^ word) {
	int index = this->binarySearchWord(word, 0, this->wordList->Count - 1);
	if (index != -1) {
		return true;
	} else {
		return false;
	}
}

/**
 * Returns the specified number of random letters.
 *
 * @pre totalLetters > 0
 *
 * @return the specified number of random letters.
 */
String^ GameController::getRandomLetters(int totalLetters) {
	Random^ generator = gcnew Random();
	array<char>^ letters = { 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
		't', 't', 't', 't', 't', 't', 't', 't', 't', 
		'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'a', 'a', 'a', 'a', 'a', 'a',
		'i', 'i', 'i', 'i', 'i', 'i', 'n', 'n', 'n', 'n', 'n', 'n',
		's', 's', 's', 's', 's', 's', 'h', 'h', 'h', 'h', 'h', 'h', 'r', 'r',
		'r', 'r', 'r', 'l', 'l', 'l', 'l', 'd', 'd', 'd', 'u', 'u', 'u', 'w',
		'w', 'w', 'y', 'y', 'y', 'b', 'b', 'c', 'c', 'f', 'f', 'g', 'g', 'm',
		'm', 'p', 'p', 'v', 'v', 'j', 'k', 'q', 'x', 'z' };
	StringBuilder^ builder = gcnew StringBuilder();
	for (int i = 0; i < totalLetters; i++) {
		int randomIndex = generator->Next(0, letters->Length);
		char randomLetter;
		do {
			randomLetter = letters[randomIndex];
			builder->Append(Char::ToString(randomLetter));

			letters[randomIndex] = '?';
		} while (randomLetter == '?');
	}
	return builder->ToString();
}

String^ GameController::shuffleLetters(String^ lettersToShuffle) {
	Random^ random = gcnew Random();
	List<char>^ letters = this->stringToChars(lettersToShuffle);

	for (int i = letters->Count; i > 1; i--)
	{
	    int j = random->Next(i);
	    char tmp = letters[j];
	    letters[j] = letters[i - 1];
	    letters[i - 1] = tmp;
	}
	StringBuilder^ builder = gcnew StringBuilder();
	for(int i = 0; i < letters->Count; i++) {
		builder->Append(Char::ToString(letters[i]));
	}
	return builder->ToString();
}

List<char>^ GameController::stringToChars(String^ word) {
	List<char>^ letters = gcnew List<char>();
	for (int i = 0; i < word->Length; i++) {
		letters->Add(word[i]);
	}
	return letters;
}

void GameController::setName(String^ name) {
	this->player->setName(name);
}

bool GameController::wordIsValidAndAllowed(String^ word, String^ allowedCharacters) {
	if (this->wordContainsAllowedCharacters(word, allowedCharacters)) {
		if (this->contains(word)) {
			return true;
		}
	} else {
		return false;
	}
}

bool GameController::wordContainsAllowedCharacters(String^ word, String^ allowedCharacters) {
	List<char>^ allowedArray = this->stringToChars(allowedCharacters);
	bool allowed = true;
	for (int i = 0; i < word->Length; i++) {
		if (!allowedArray->Contains(word[i])) {
			return false;
		}
	}

	return true;
}

}