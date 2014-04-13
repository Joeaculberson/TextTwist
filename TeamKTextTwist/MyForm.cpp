#include "MyForm.h"

using namespace System::Windows::Forms;
using namespace System::Text;

#include "FileIO.h"
using namespace model;

#include "OptionsDialog.h"
#include "HighScoresDialog.h"
using namespace controller;

namespace Project1 {

System::Void MyForm::generateButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->handleGenerateEvent();
}

System::Void MyForm::shuffleButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->handleShuffle();
}

System::Void MyForm::nameBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->toggleStartButtonEnabled();
}

System::Void MyForm::startButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->beginNewGame();
}

System::Void MyForm::submitButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->submitWord();
}

System::Void MyForm::optionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->showOptionsMenu();
}

System::Void MyForm::exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Form::Close();
}

System::Void MyForm::newGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->startNewGame();
}

System::Void MyForm::highScoresToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	FileIO^ file = gcnew FileIO();
	List<Player^>^ highScores = file->loadHighScores();
	if (highScores->Count == 0) {
		MessageBox::Show("There are no high scores to display.");
	} else {
		HighScoresDialog^ highScoreDialog = gcnew HighScoresDialog(highScores);
		highScoreDialog->ShowDialog();
	}
	
}

System::Void MyForm::clearAllButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->guessBox->Text = "";
}

System::Void MyForm::newGameButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->startNewGame();
}

System::Void MyForm::lettersBox_Click(System::Object^ sender, System::EventArgs^ e) {
	this->newGameButton->Focus();
}

System::Void MyForm::guessedWords_Click(System::Object^ sender, System::EventArgs^ e) {
	this->newGameButton->Focus();
}

void MyForm::startNewGame() {
	this->nameBox->Text = "";
	this->lettersBox->Text = "";
	this->shuffleButton->Enabled = false;
	this->generateButton->Enabled = false;
	this->submitButton->Enabled = false;
	this->gc->createNewPlayer();
	this->scoreLabel->Text = this->gc->getPlayerScoreString();
	this->guessedWords->Text = "";
}

void MyForm::performIfReuseIsOff(String^ value, String^ allowedLetters) {
	if (!this->reuseLetters)
	{
			String^ newAllowedLetters = this->removeCharacters(value, allowedLetters);
			this->lettersBox->Text = newAllowedLetters; 
	}
}

void MyForm::handleWordEntry() {
	String^ value = this->guessBox->Text;
	Word^ newWord = gcnew Word(value);
	String^ allowedLetters = this->lettersBox->Text;
	if (this->gc->isWordValid(newWord, allowedLetters)) {
		int pointValue = newWord->getPointValue();
		this->guessedWords->AppendText(value + " (" + pointValue + ")" + "\n");
		this->gc->incrementPlayerScore(pointValue);
		this->performIfReuseIsOff(value, allowedLetters);
		this->scoreLabel->Text = this->gc->getPlayerScoreString();
	} else {
		MessageBox::Show("Word not allowed. You have lost one point.");
		this->gc->decrementPlayerScore();
		this->scoreLabel->Text = this->gc->getPlayerScoreString();
	}
}

void MyForm::submitWord() {
	if (this->guessBox->Text->Length >= 3) {
		this->handleWordEntry();
	} else {
		MessageBox::Show("Your guess must be at least three letters long");
	}
	this->guessBox->Text = "";
}

void MyForm::handleGenerateEvent() {
	this->lettersBox->Text = gc->getRandomLetters(7);
	this->shuffleButton->Enabled = true;
}

void MyForm::handleShuffle() {
	if (this->lettersBox->Text != "") {
		String^ letters = this->lettersBox->Text;
		letters = this->gc->shuffleLetters(letters);
		this->lettersBox->Text = letters;
	}
}

void MyForm::toggleStartButtonEnabled() {
	if (this->nameBox->Text->Length != 0) {
		this->startButton->Enabled = true;
	} else {
		this->startButton->Enabled = false;
	}
}

void MyForm::beginNewGame() {
	String^ playerName = this->nameBox->Text;
	this->gc->setPlayerName(playerName);
	this->generateButton->Enabled = true;
	this->submitButton->Enabled = true;
}

String^ MyForm::removeCharacters(String^ ofWord, String^ fromString) {
	List<char>^ fromList = this->gc->stringToChars(fromString);
	for (int i = 0; i < ofWord->Length; i++) {
		fromList->Remove(ofWord[i]);
	}

	StringBuilder^ builder = gcnew StringBuilder();
	for (int i = 0; i < fromList->Count; i++) {
		builder->Append(Char::ToString(fromList[i]));
	}

	return builder->ToString();
}

void MyForm::showOptionsMenu() {
	OptionsDialog^ optionsDialog = gcnew OptionsDialog(this->timeLimit, this->reuseLetters);

	if (optionsDialog->ShowDialog() == ::DialogResult::OK) {
		this->reuseLetters = optionsDialog->getLetterReuse();
		this->timeLimit = optionsDialog->getTimeLimit();
	}
}
}