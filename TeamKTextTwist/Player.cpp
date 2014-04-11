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

}
