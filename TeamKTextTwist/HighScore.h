#pragma once

#include "Player.h"

namespace model {

ref class HighScore
{
public:
	HighScore(Player^ player, int timeAllotted);
	Player^ getPlayer();
	int getTimeAllotted();
private:
	Player^ player;
	int timeAllotted;
};

}