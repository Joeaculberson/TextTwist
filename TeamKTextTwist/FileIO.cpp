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
		String^ fileName = L"dictionary.txt";

		try {
			StreamReader^ input = File::OpenText(fileName);

			String^ line;
			while((line = input->ReadLine()) != nullptr) {
				words->Add(line);
			}
			input->Close();
		} catch (Exception^ exception) {
			Console::WriteLine("Error: " + exception->Message);
		}

		return words;
	}


	void FileIO::addHighScore(Player player) {
		List<Player^>^ highScores = this->loadHighScores();
		List<Player^>^ sortedHighScores = gcnew List<Player^>();

		if (highScores->Count != 0) {
			//sort players
		}

		StreamWriter^ sw = gcnew StreamWriter(L"highscores.txt");
		for each (Player^ currPlayer in sortedHighScores)
		{
			sw->WriteLine(currPlayer->getName() + "/" + Convert::ToString(currPlayer->getScore()));
		}
		sw->Flush();
		sw->Close();
		
	}

	List<Player^>^ FileIO::loadHighScores() {
		String^ fileName = L"highscores.txt";
		List<Player^>^ highScores = gcnew List<Player^>();
		StreamReader^ input = File::OpenText(fileName);
		String^ line;

		while((line = input->ReadLine()) != nullptr) {
			array<String^>^ rawPerson = line->Split('/');
			Player^ player = gcnew Player(rawPerson[0]);
			player->setScore(Convert::ToInt32(rawPerson[1]));

			highScores->Add(player);
		}

		return highScores;
	}
}