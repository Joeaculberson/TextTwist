#pragma once
using namespace System;
using namespace System::Collections::Generic;

namespace model {
	ref class FileIO
	{
	public:
		FileIO(void);
		static List<String^>^ parseFile();
	};
}

