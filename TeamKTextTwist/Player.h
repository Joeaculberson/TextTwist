#pragma once

using namespace System;

namespace model {

ref class Player
{
private:
	String^ name;
	int score;
	int coins;

public:
	Player();
	Player(String^ name);
	int getScore();
	void setScore(int score);
	int getCoins();
	void setCoins(int coins);
	String^ getName();
	void setName(String^ name);
	String^ getScoreString();
	String^ getCoinsString();

	bool operator<(const Player^ player);
	bool operator<=(const Player^ player);
	bool operator>(const Player^ player);
	bool operator>=(const Player^ player);
};

}

