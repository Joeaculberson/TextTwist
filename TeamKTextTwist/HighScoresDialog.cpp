#include "HighScoresDialog.h"

using namespace System::Collections::Generic;

namespace controller {

///<summary>
/// Creates a high score dialog with assigned values.
///</summary>
///<pre> highScores != nullptr </pre>
///<param value="highScores">The high scores to display</param>
HighScoresDialog::HighScoresDialog(List<HighScore^>^ highScores)
{
	InitializeComponent();
	if (highScores->Count == 0) {
		MessageBox::Show("There are no high scores to display.");
	} else {
		for each (HighScore^ currPlayer in highScores)
		{
			this->addHighScore(currPlayer);
		}
	}
}

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