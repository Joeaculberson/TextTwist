#include "Player.h"

namespace model {

Player::Player() {
	this->name = "";
	this->score = 0;
}
Player::Player(String^ name)
{
	this->name = name;
	this->score = 0;
}

int Player::getScore() {
	return this->score;
}

void Player::setScore(int score) {
	if (score < 0) {
		throw gcnew ArgumentException("Score cannot be negative.");
	}
	this->score = score;
}

int Player::getCoins() {
	return this->coins;
}

void Player::setCoins(int coins) {
	if (coins < 0) {
		throw gcnew ArgumentException("Coins cannot be negative");
	}
	this->coins = coins;
}

String^ Player::getName() {
	return this->name;
}

void Player::setName(String^ name) {
	this->name = name;
}

bool Player::operator<(const Player^ player) {
	return this->score < player->score;
}

bool Player::operator<=(const Player^ player) {
	return this->score <= player->score;
}

bool Player::operator>(const Player^ player) {
	return this->score > player->score;
}

bool Player::operator>=(const Player^ player) {
	return this->score >= player->score;
}

String^ Player::getScoreString() {
	return "Score: " + this->score;
}

String^ Player::getCoinsString() {
	return "Coins: " + this->coins;
}

}
