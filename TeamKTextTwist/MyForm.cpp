#include "MyForm.h"

using namespace System::Windows::Forms;
using namespace System::Text;

#include "FileIO.h"
using namespace model;

#include "OptionsDialog.h"
#include "HighScoresDialog.h"
using namespace controller;

namespace Project1 {

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
	List<HighScore^>^ highScores = file->loadHighScores();
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

System::Void MyForm::guessedWordsBox_Click(System::Object^ sender, System::EventArgs^ e) {
	this->newGameButton->Focus();
}

void MyForm::startNewGame() {
	this->nameBox->Text = "";
	this->lettersBox->Text = "";
	this->guessBox->Text = "";
	this->shuffleButton->Enabled = false;
	this->nameBox->BringToFront();
	this->submitButton->Enabled = false;
	this->submitButton->SendToBack();
	this->newGameButton->Enabled = true;
	this->newGameButton->BringToFront();
	this->clearAllButton->Enabled = false;
	this->enterName->Visible = true;
	this->gc->createNewPlayer();
	this->scoreLabel->Text = this->gc->getPlayerScoreString();
	this->guessedWordsBox->Text = "";
	this->timer->Stop();
	this->timeLimit = this->userSetTimeLimit;
	this->secondsLeft = 0;
	this->timerLabel->Text = this->timeLimit + ":00";
}

void MyForm::handleWordEntry() {
	String^ value = this->guessBox->Text;
	Word^ newWord = gcnew Word(value);
	String^ allowedLetters = this->lettersBox->Text;
	if (this->gc->isWordValid(newWord, allowedLetters, this->reuseLetters)) {
		int pointValue = newWord->getPointValue();
		this->guessedWordsBox->AppendText(value + " (" + pointValue + ")" + Environment::NewLine);
		this->gc->incrementPlayerScore(pointValue);
		this->scoreLabel->Text = this->gc->getPlayerScoreString();
	} else {
		String^ losingMessage = "Your word is not in the dictionary.";
		if (this->gc->getPlayer()->getScore() > 0) {
			MessageBox::Show(losingMessage + " You have lost one point.");
			this->gc->decrementPlayerScore();
			this->scoreLabel->Text = this->gc->getPlayerScoreString();
		} else {
			MessageBox::Show(losingMessage);
		}
	}
}

void MyForm::submitWord() {
	if (this->guessBox->Text->Length >= MIN_LETTER_LENGTH) {
		this->handleWordEntry();
	} else {
		MessageBox::Show("Your guess must be at least three letters long.");
	}
	this->guessBox->Text = "";
}

void MyForm::handleGenerateEvent() {
	this->generatedLetters = gc->getRandomLetters(7);
	this->lettersBox->Text = this->generatedLetters;
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
	if (playerName->Contains("/")) {
		MessageBox::Show("Invalid name. Please try again.");
	} else {
		this->enterName->Visible = false;
		this->guessBox->BringToFront();
		this->startButton->SendToBack();
		this->startButton->Enabled = false;
		this->clearAllButton->Enabled = true;
		this->gc->setPlayerName(playerName);
		this->submitButton->Enabled = true;
		this->handleGenerateEvent();
		this->timer->Start();
	}
}

void MyForm::showOptionsMenu() {
	OptionsDialog^ optionsDialog = gcnew OptionsDialog(this->userSetTimeLimit, this->reuseLetters);

	if (optionsDialog->ShowDialog() == ::DialogResult::OK) {
		::DialogResult dialogResult = MessageBox::Show("For changes to apply, the game must reset. Reset game?", "Reset", MessageBoxButtons::YesNo);
		if (dialogResult == ::DialogResult::Yes) {
			this->reuseLetters = optionsDialog->getLetterReuse();
			this->timeLimit = optionsDialog->getTimeLimit();
			this->userSetTimeLimit = optionsDialog->getTimeLimit();
			this->startNewGame();
		}
	}
}

System::Void MyForm::timer_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (this->timeLimit > 0 || this->secondsLeft > 0)
    {
		if(this->secondsLeft == 0) {
			this->timeLimit = this->timeLimit - 1;
			this->secondsLeft = 59;
		} else {
			this->secondsLeft = this->secondsLeft - 1;
		}

		if (this->secondsLeft < 10) {
			timerLabel->Text = this->timeLimit + ":" + "0" + this->secondsLeft;
		} else if (this->secondsLeft == 0) {
			timerLabel->Text = this->timeLimit + ":00";
		} else {
			timerLabel->Text = this->timeLimit + ":" + this->secondsLeft;
		}
    }
    else
    {
        this->endGame();
		MessageBox::Show("Time up! Game over.");
    }
}

void MyForm::endGame() {
	this->timer->Stop();
    this->timerLabel->Text = "0:00";
	this->lettersBox->Text = "";
    this->nameBox->Text = "";
	this->guessBox->Text = "";
	this->shuffleButton->Enabled = false;
	this->submitButton->SendToBack();
	this->submitButton->Enabled = false;
	this->startButton->BringToFront();
	this->startButton->Enabled = true;
	this->guessBox->BringToFront();
	this->clearAllButton->Enabled = false;
	this->timeLimit = this->userSetTimeLimit;
	this->secondsLeft = 0;
	this->enterName->Visible = true;

	HighScore^ highScore = gcnew HighScore(this->gc->getPlayer(), this->userSetTimeLimit);
	this->file->addHighScore(highScore);
}

}