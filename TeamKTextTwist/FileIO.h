#pragma once
using namespace System;
using namespace System::Collections::Generic;

#include "Player.h"
#include "HighScore.h"

namespace model {
	ref class FileIO
	{
	public:
		FileIO(void);
		List<String^>^ parseFile();
		void addHighScore(HighScore^ highScore);
		List<HighScore^>^ loadHighScores();
		void clearList();
	private:
		static int compare(HighScore^ score, HighScore^ otherScore) {
			return otherScore->getPlayer()->getScore() - score->getPlayer()->getScore();
		}

		static int MAX_HIGH_SCORES = 10;
	};
}

