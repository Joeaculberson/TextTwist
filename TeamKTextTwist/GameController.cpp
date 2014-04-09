#include "GameController.h"
#include "FileIO.h"

using namespace System::Text;

using namespace System;
using namespace model;

namespace controller {
GameController::GameController(List<String^>^ wordList)
{
	this->wordList = this->fileIO->parseFile();
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
	return (first + last) / 2;
}

bool GameController::contains(String^ word) {
	return !(this->binarySearchWord(word, 0, this->wordList->Count - 1) == -1);
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
		do {
			builder->Append(letters[randomIndex]);
			letters[randomIndex] = '?';
		} while (letters[randomIndex] != '?');
	}
	return builder->ToString();
}

}