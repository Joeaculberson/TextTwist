using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;

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

	String^ fileName = "dictionary.txt";

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

void FileIO::addHighScore(HighScore^ highScore) {
	List<HighScore^>^ highScores = this->loadHighScores();
	highScores->Add(highScore);

	Comparison<HighScore^>^ comparisonDelegate = gcnew Comparison<HighScore^>(&compare);
	highScores->Sort(comparisonDelegate);

	if (highScores->Count >= MAX_HIGH_SCORES) {
		highScores->RemoveAt(MAX_HIGH_SCORES);
	}

	StreamWriter^ sw = gcnew StreamWriter(L"highscores.txt");
	for (int i = 0; i < highScores->Count; i++)
	{
		sw->WriteLine(highScores[i]->getPlayer()->getName() + "/" + Convert::ToString(highScores[i]->getPlayer()->getScore()));
	}
	sw->Flush();
	sw->Close();
}

void FileIO::clearList() {
	File::Create(L"highscores.txt")->Close();
}

List<HighScore^>^ FileIO::loadHighScores() {
	String^ fileName = L"highscores.txt";
	List<HighScore^>^ highScores = gcnew List<HighScore^>();
	StreamReader^ input = File::OpenText(fileName);
	String^ line;

	while((line = input->ReadLine()) != nullptr) {
		array<String^>^ rawPerson = line->Split('/');
		Player^ player = gcnew Player(rawPerson[0]);
		player->setScore(Convert::ToInt32(rawPerson[1]));
		HighScore^ highScore = gcnew HighScore(player, Convert::ToInt32(rawPerson[2]));

		highScores->Add(highScore);
	}
	input->Close();

	return highScores;
}



}