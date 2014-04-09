#include "Player.h"

namespace model {

Player::Player(String^ name)
{
	this->name = name;
	this->score = 0;
}

int Player::getScore() {
	return this->score;
}

void Player::setScore(int score) {
	if (score > 0) {
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

}
