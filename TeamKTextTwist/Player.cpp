#include "Player.h"

namespace model {

/// <summary>
/// Default constructer for the player class.
/// </summary>
/// <pre>None.</pre>
Player::Player() {
	this->name = "";
	this->score = 0;
}

/// <summary>
/// Creates a player object with assigned values.
/// </summary>
/// <pre>name != nullptr</pre>
/// <post> name == this->getName()
/// <param value="name">The name of the player</param>
Player::Player(String^ name)
{
	if(name == nullptr) {
		throw gcnew ArgumentException("Name cannot be null.");
	}
	this->name = name;
	this->score = 0;
}

/// <summary>
/// Returns the player's score.
/// </summary>
/// <pre>None.</pre>
/// <returns>The player's score.</returns>
int Player::getScore() {
	return this->score;
}

/// <summary>
/// Sets the player's score
/// </summary>
/// <pre>score > 0</pre>
/// <param value="score">The player's score</param>
/// <returns>The point value of the word</returns>
void Player::setScore(int score) {
	if (score < 0) {
		throw gcnew ArgumentException("Score cannot be negative.");
	}
	this->score = score;
}

/// <summary>
/// Returns the player's coins.
/// </summary>
/// <pre>None.</pre>
/// <returns>The player's coins.</returns>
int Player::getCoins() {
	return this->coins;
}

/// <summary>
/// Sets the player's coin.
/// </summary>
/// <pre>coin > 0</pre>
/// <param value="coins">The player's coins to set.</param>
void Player::setCoins(int coins) {
	if (coins < 0) {
		throw gcnew ArgumentException("Coins cannot be negative");
	}
	this->coins = coins;
}

/// <summary>
/// Returns the player's name.
/// </summary>
/// <pre>None.</pre>
/// <returns>The name of the player.</returns>
String^ Player::getName() {
	return this->name;
}

/// <summary>
/// Sets the name of the player.
/// </summary>
/// <pre>name != nullptr</pre>
/// <param value="name">The name of the player</param>
void Player::setName(String^ name) {
	if (name == nullptr) {
		throw gcnew ArgumentException("Name of the player was null.");
	}
	this->name = name;
}

/// <summary>
/// The overload operator < for the player. Compares by score.
/// </summary>
/// <pre>None.</pre>
/// <param value="player">The player to compare to.</param>
/// <returns>True if this player has a lower score than the passed player.</returns>
bool Player::operator<(const Player^ player) {
	return this->score < player->score;
}

/// <summary>
/// The overload operator <= for the player. Compares by score.
/// </summary>
/// <pre>None.</pre>
/// <param value="player">The player to compare to.</param>
/// <returns>True if this player has a score that is less than or equal to than the passed player.</returns>
bool Player::operator<=(const Player^ player) {
	return this->score <= player->score;
}

/// <summary>
/// The overload operator > for the player. Compares by score.
/// </summary>
/// <pre>None.</pre>
/// <param value="player">The player to compare to.</param>
/// <returns>True if this player has a higher score than the passed player.</returns>
bool Player::operator>(const Player^ player) {
	return this->score > player->score;
}

/// <summary>
/// The overload operator >= for the player. Compares by score.
/// </summary>
/// <pre>None.</pre>
/// <param value="player">The player to compare to.</param>
/// <returns>True if this player has a greater than or equal to score than the passed player.</returns>
bool Player::operator>=(const Player^ player) {
	return this->score >= player->score;
}

}
