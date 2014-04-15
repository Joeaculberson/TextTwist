#include "GameController.h"
#include "FileIO.h"
#include <iostream>

using namespace System::Text;



namespace model {

GameController::GameController()
{
	this->fileIO = gcnew FileIO();
	this->wordList = this->fileIO->parseFile();
	int length = this->wordList->Count;
	this->player = gcnew Player();
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
		builder->Append(chooseLetter(generator, letters));
	}
	return builder->ToString();
}

String^ GameController::chooseLetter(Random^ generator, array<char>^ letters) {
	char randomLetter;

	do {
		int randomIndex = generator->Next(0, letters->Length);
		randomLetter = letters[randomIndex];
		letters[randomIndex] = '?';
	} while (randomLetter == '?');

	return Char::ToString(randomLetter);
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

List<char>^ GameController::stringToChars(String^ toConvert) {
	List<char>^ letters = gcnew List<char>();
	for (int i = 0; i < toConvert->Length; i++) {
		letters->Add(toConvert[i]);
	}
	return letters;
}

String^ GameController::getPlayerName() {
	return this->player->getName();
}

void GameController::setPlayerName(String^ name) {
	this->player->setName(name);
}

bool GameController::isWordValid(Word^ word, String^ allowedLetters, bool reuseLetters) {
	List<char>^ allowedList = this->stringToChars(allowedLetters);
	return word->isValid(this->wordList, allowedList, reuseLetters);
}

void GameController::incrementPlayerScore(int number) {
	this->player->setScore(this->player->getScore() + number);
}

void GameController::decrementPlayerScore() {
	this->player->setScore(this->player->getScore() - 1);
}

void GameController::createNewPlayer() {
	this->player = gcnew Player();
}

void GameController::incrementPlayerCoins(int coins) {
	this->player->setCoins(this->player->getCoins() + coins);
}

void GameController::decrementPlayerCoins(int coins) {
	this->player->setCoins(this->player->getCoins() - coins);
}

int GameController::getPlayerScore() {
	return this->player->getScore();
}

int GameController::getPlayerCoins() {
	return this->player->getCoins();
}

Player^ GameController::getPlayer() {
	return this->player;
}

}