#include "HighScore.h"

namespace model {

HighScore::HighScore(Player^ player, int timeAllotted)
{
	this->player = player;
	this->timeAllotted = timeAllotted;
}

Player^ HighScore::getPlayer() {
	return this->player;
}

int HighScore::getTimeAllotted() {
	return this->timeAllotted;
}

}