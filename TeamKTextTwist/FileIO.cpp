using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::

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
		String^ fileName = L"dictionary.txt";

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


	void FileIO::addHighScore(Player player) {
		String^ fileName = "highscores.txt";
		List<Player^>^ highScores = gcnew List<Player^>();
		StreamReader^ input = File::OpenText(fileName);
		String^ line;

		while((line = input->ReadLine()) != nullptr) {
			array<String^>^ rawPerson = line->Split('/');
			Player^ player = gcnew Player(rawPerson[0]);
			player->setScore(Convert::ToInt32(rawPerson[1]));

			highScores->Add(player);
		}

		List<Player^>^ sortedHighScores = gcnew List<Player^>();
		if (highScores != nullptr) {
			//sort by score
		}

		StreamWriter^ sw = gcnew StreamWriter(fileName);

		//write list back out to file, overwriting the old one.
	}
}

