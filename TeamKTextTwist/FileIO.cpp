using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

#include "FileIO.h"

namespace model {

	/**
	 * Creates a file io object with assigned values.
	 *
	 * @pre none
	 */
	FileIO::FileIO(void)
	{
		
	}
	
   /**
	* Parses the dictionary and returns the words.
	* 
	* @pre none
	*
	* @return The words in the dictionary.
	*/
	List<String^>^ FileIO::parseFile() 
	{
		//vector<string> words = vector<string>();
		List<String^>^ words = gcnew List<String^>();

		//string word;
		String^ fileName = "dictionary.txt";

		try {
			StreamReader^ input = File::OpenText(fileName);

			String^ line;
			while((line = input->ReadLine()) != nullptr) {
				words->Add(line);
			}
		} catch (Exception^ exception) {
			//not found
		}

		return words;
	}
}

