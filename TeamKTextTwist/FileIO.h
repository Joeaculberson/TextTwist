#pragma once
using namespace System;
using namespace System::Collections::Generic;

#include "Player.h"
#include "HighScore.h"
using namespace model;

namespace fileio {
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
		void addHighScoreFromFile(String^ line, List<HighScore^>^ highScores);

		static int MAX_HIGH_SCORES = 10;
	};
}

