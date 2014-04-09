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
		void addHighScore(Player player);
	};
}

