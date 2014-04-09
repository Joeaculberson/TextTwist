#pragma once

#include <string>
#include <vector>
using namespace std;

namespace model {
	ref class FileIO
	{
	public:
		FileIO();
		vector<string>* parseFile();
	};
}

