#include "HighScoresDialog.h"

namespace controller {

void HighScoresDialog::addHighScore(HighScore^ highScore)
{
	this->highScoreGrid->Rows->Add(highScore->getPlayer()->getName(), highScore->getPlayer()->getScore(), highScore->getTimeAllotted());
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