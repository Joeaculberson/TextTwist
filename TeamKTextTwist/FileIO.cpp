#include "FileIO.h"

#include <iostream>
#include <fstream>
#include <algorithm>

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
	* Parses the dictionary and returns the words with their appropriate subwords.
	* 
	* @pre none
	*
	* @return The words with their appropriate subwords.
	*/
	map<string, vector<string>> FileIO::parseFile() 
	{
		map<string, vector<string>> words = map<string, vector<string>>();
		string word;
		ifstream myfile("dictionary.txt");

		if (myfile.is_open())
		{
			while (getline(myfile, word))
			{
				string alphabetizedLetters = word;
				sort(alphabetizedLetters.begin(), alphabetizedLetters.end());

				if (words.find(alphabetizedLetters) == words.end())
				{
					words.insert(pair<string, vector<string>>(alphabetizedLetters, vector<string>()));
				} 
				else
				{
					words[alphabetizedLetters].push_back(word);
				}
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

