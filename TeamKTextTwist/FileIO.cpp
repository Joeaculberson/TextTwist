using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;

#include "FileIO.h"

namespace fileio {

FileIO::FileIO(void)
{
		
}
	
List<String^>^ FileIO::parseFile() 
{
	List<String^>^ words = gcnew List<String^>();

	String^ fileName = L"dictionary.txt";

	try {
		StreamReader^ input = File::OpenText(fileName);

		String^ line;
		while((line = input->ReadLine()) != nullptr) {
			words->Add(line);
		}
		input->Close();
	} catch (Exception^ exception) {
		Console::WriteLine(L"Error: " + exception->Message);
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

	try {
		StreamWriter^ sw = gcnew StreamWriter(L"highscores.txt");
		for (int i = 0; i < highScores->Count; i++)
		{
			sw->WriteLine(highScores[i]->getPlayer()->getName() + "/" + Convert::ToString(highScores[i]->getPlayer()->getScore())+ "/" + Convert::ToString(highScore->getTimeAllotted()));
		}
		sw->Flush();
		sw->Close();
	} catch (Exception^ exception) {
		Console::WriteLine(L"Error: " + exception->Message);
	}
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
		this->addHighScoreFromFile(line, highScores);
	}
	input->Close();

	return highScores;
}

void FileIO::addHighScoreFromFile(String^ line, List<HighScore^>^ highScores) {
	array<String^>^ rawPerson = line->Split('/');
	Player^ player = gcnew Player(rawPerson[0]);
	player->setScore(Convert::ToInt32(rawPerson[1]));
	HighScore^ highScore = gcnew HighScore(player, Convert::ToInt32(rawPerson[2]));

	highScores->Add(highScore);
}

}