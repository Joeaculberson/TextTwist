#include "HighScoresDialog.h"

using namespace System::Collections::Generic;
using namespace System;

namespace controller {

void HighScoresDialog::addHighScore(Player^ player)
{
	this->highScoreGrid->Rows->Add(player->getName(), player->getScore());
}

System::Void HighScoresDialog::resetBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	FileIO^ file = gcnew FileIO();
	file->clearList();
	MessageBox::Show("The list has been cleared.");
	this->Close();
}

System::Void HighScoresDialog::closeBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

}