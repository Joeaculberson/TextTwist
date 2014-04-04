#pragma once

#include <string>
#include <map>
#include <vector>
using namespace std;

namespace model {
	ref class FileIO
	{
	public:
		FileIO();
		map<string, vector<string>> parseFile();
	};
}

