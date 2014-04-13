#pragma once
using namespace System;
using namespace System::Collections::Generic;

#include "Player.h"

namespace model {
	ref class FileIO
	{
	public:
		FileIO(void);
		List<String^>^ parseFile();
		void addHighScore(Player^ player);
		List<Player^>^ loadHighScores();
		void clearList();
	private:
		static int compare(Player^ player, Player^ otherPlayer) {
			return otherPlayer->getScore() - player->getScore();
		}

		static int MAX_HIGH_SCORES = 10;
	};
}

