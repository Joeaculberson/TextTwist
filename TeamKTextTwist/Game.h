#pragma once

#include <string>
using namespace std;

namespace controller {
	ref class Game
	{
	public:
			Game();
			void run();
	private:
			string randomlySelectLetters();
	};
}

