#include "FileIO.h"

#include <iostream>
#include <fstream>

namespace model {

	/**
	 * Creates a file io object with assigned values.
	 *
	 * @pre none
	 */
	FileIO::FileIO()
	{
		
	}
	
   /**
	* Parses the dictionary and returns the words.
	* 
	* @pre none
	*
	* @return The words in the dictionary.
	*/
	vector<string>* FileIO::parseFile() 
	{
		vector<string> words = vector<string>();

		string word;
		ifstream myfile("dictionary.txt");

		if (myfile.is_open())
		{
			while (getline(myfile, word))
			{
				words.push_back(word);
			}
			myfile.close();
		}
		else 
		{
			//file not found
		} 

		return words;
	}

}

