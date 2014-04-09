#pragma once

using namespace System;

namespace model {

ref class Player
{
private:
	String^ name;
	int score;

public:
	Player(String^ name);
	int getScore();
	void setScore(int score);
	String^ getName();
	void setName(String^ name);
};

}

