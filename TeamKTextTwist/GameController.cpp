#include "GameController.h"
#include "FileIO.h"

using namespace System::Text;

namespace model {

/// <summary>
/// The default for the game controller class.
/// </summary>
/// <pre>None.</pre>
GameController::GameController()
{
	this->fileIO = gcnew FileIO();
	this->wordList = this->fileIO->parseFile();
	int length = this->wordList->Count;
	this->player = gcnew Player();
}

/// <summary>
/// Returns a requested number of random letters.
/// </summary>
/// <pre>totalLetters > 0</pre>
/// <param value="totalLetters">The number of letters to generate.</param>
/// <return>The randomly generated letters.</return>
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
		char randomLetter;

	do {
		int randomIndex = generator->Next(0, letters->Length);
		randomLetter = letters[randomIndex];
		letters[randomIndex] = '?';
	} while (randomLetter == '?');

	builder->Append(Char::ToString(randomLetter));
	}
	return builder->ToString();
}

/// <summary>
/// Shuffles the letters using the fisher yates shuffle.
/// </summary>
/// <pre>lettersToShuffle != nullptr</pre>
/// <param value="totalLetters">The number of letters to generate.</param>
/// <return>The randomly generated letters.</return>
String^ GameController::shuffleLetters(String^ lettersToShuffle) {
	if (lettersToShuffle == nullptr) {
		throw gcnew ArgumentException("letters to shuffle were null.");
	}
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

/// <summary>
/// Converts a string to a char array.
/// </summary>
/// <pre>toConvert != nullptr</pre>
/// <param value="toConvert">The string to convert.</param>
/// <return>The list of characters.</return>
List<char>^ GameController::stringToChars(String^ toConvert) {
	if (toConvert == nullptr) {
		throw gcnew ArgumentException("Letters to convert was null.");
	}
	List<char>^ letters = gcnew List<char>();
	for (int i = 0; i < toConvert->Length; i++) {
		letters->Add(toConvert[i]);
	}
	return letters;
}

/// <summary>
/// Returns the player's name.
/// </summary>
/// <pre>None.</pre>
/// <return>The player's name.</return>
String^ GameController::getPlayerName() {
	return this->player->getName();
}

/// <summary>
/// Sets the player's name.
/// </summary>
/// <pre>name != nullptr</pre>
/// <param value="name">The name of the player to set.</param>
void GameController::setPlayerName(String^ name) {
	this->player->setName(name);
}

/// <summary>
/// Returns true if the word is valid.
/// </summary>
/// <pre>word != nullptr</pre>
/// <pre>allowedLetters != nullptr</pre>
/// <param value="word">The word to check that is valid.</param>
/// <param value="allowedLetters">The allowed letters to check against.</param>
/// <param value="reuseLetters">If letter reuse is allowed.</param>
/// <return>True if the word is valid</return>
bool GameController::isWordValid(Word^ word, String^ allowedLetters, bool reuseLetters) {
	List<char>^ allowedList = this->stringToChars(allowedLetters);
	return word->isValid(this->wordList, allowedList, reuseLetters);
}

/// <summary>
/// Increments the player's score.
/// </summary>
/// <pre>None.</pre>
/// <param value="name">The number to increment the score by.</param>
void GameController::incrementPlayerScore(int number) {
	this->player->setScore(this->player->getScore() + number);
}

/// <summary>
/// Decrements the player's score.
/// </summary>
/// <pre>None.</pre>
/// <param value="name">The number to decrement the score by.</param>
void GameController::decrementPlayerScore() {
	this->player->setScore(this->player->getScore() - 1);
}

/// <summary>
/// Creates a new player object.
/// </summary>
/// <pre>None.</pre>
void GameController::createNewPlayer() {
	this->player = gcnew Player();
}

/// <summary>
/// Increments the player's coins.
/// </summary>
/// <pre>coins > 0</pre>
/// <param value="coin">The amount to increment by.</param>
void GameController::incrementPlayerCoins(int coins) {
	this->player->setCoins(this->player->getCoins() + coins);
}

/// <summary>
/// Decrements the player's coins.
/// </summary>
/// <pre>coins > 0</pre>
/// <param value="name">The number to decrement the coins by.</param>
void GameController::decrementPlayerCoins(int coins) {
	this->player->setCoins(this->player->getCoins() - coins);
}

/// <summary>
/// Returns the player's score.
/// </summary>
/// <pre>None.</pre>
/// <return>The player's score.</return>
int GameController::getPlayerScore() {
	return this->player->getScore();
}

/// <summary>
/// Returns the player's coins.
/// </summary>
/// <pre>None.</pre>
/// <return>The player's coins.</return>
int GameController::getPlayerCoins() {
	return this->player->getCoins();
}

/// <summary>
/// Returns the player.
/// </summary>
/// <pre>None.</pre>
/// <return>The player.</return>
Player^ GameController::getPlayer() {
	return this->player;
}

}