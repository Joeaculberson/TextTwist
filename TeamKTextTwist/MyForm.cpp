#include "MyForm.h"

using namespace System::Windows::Forms;
using namespace System::Text;


#include "OptionsDialog.h"
#include "HighScoresDialog.h"
using namespace controller;

namespace controller {

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

System::Void MyForm::generateButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->handleGenerateEvent();
	this->gc->decrementPlayerCoins(2);
	this->coinsLabel->Text = this->getCoinString();
	this->toggleBuyButtonsEnabled();
}

String^ MyForm::getCoinString() {
	return this->resourceManager->GetString(L"CoinsString") + this->gc->getPlayerCoins();
}

String^ MyForm::getScoreString() {
	return this->resourceManager->GetString(L"ScoreString") + this->gc->getPlayerScore();
}

System::Void MyForm::buy30SecondsButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->secondsLeft = this->secondsLeft + 30;
	if (this->secondsLeft > 59) {
		int over = this->secondsLeft - 60;
		this->secondsLeft = over;
		this->minutesLeft = this->minutesLeft + 1;
	}
	this->gc->decrementPlayerCoins(2);
	this->toggleBuyButtonsEnabled();
	this->coinsLabel->Text = this->getCoinString();
}

System::Void MyForm::highScoresToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	List<HighScore^>^ highScores = this->file->loadHighScores();
	if (highScores->Count == 0) {
		MessageBox::Show(this->resourceManager->GetString(L"NoHighScoresOutput"));
	} else {
		HighScoresDialog^ highScoreDialog = gcnew HighScoresDialog(highScores);
		highScoreDialog->ShowDialog();
	}
}

System::Void MyForm::buy1MinuteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->minutesLeft = this->minutesLeft + 1;
	this->gc->decrementPlayerCoins(3);
	this->toggleBuyButtonsEnabled();
	this->coinsLabel->Text = this->getCoinString();
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

System::Void MyForm::nameBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == char (ENTER_KEY)) {
		this->beginNewGame();
	}
}

System::Void MyForm::guessBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == char (ENTER_KEY)) {
		this->submitWord();
	}
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
	this->scoreLabel->Text = this->getScoreString();
	this->guessedWordsBox->Text = "";
	this->timer->Stop();
	this->minutesLeft = this->userSetTimeLimit;
	this->secondsLeft = 0;
	this->timerLabel->Text = this->minutesLeft + ":00";
}

void MyForm::handleWordEntry() {
	String^ value = this->guessBox->Text;
	Word^ newWord = gcnew Word(value);
	String^ allowedLetters = this->lettersBox->Text;
	if (this->gc->isWordValid(newWord, allowedLetters, this->reuseLetters)) {
		this->processValidWord(value, newWord);
	} else {
		this->processInvalidWord(value, newWord);
	}
	this->toggleBuyButtonsEnabled();
}

void MyForm::processInvalidWord(String^ value, Word^ newWord) {
	String^ losingMessage = this->resourceManager->GetString(L"WordNotFoundOutput");
	if (this->gc->getPlayerScore() > 0) {
		MessageBox::Show(losingMessage + this->resourceManager->GetString(L"LostOnePointOutput"));
		this->gc->decrementPlayerScore();
		this->scoreLabel->Text = this->getScoreString();
	} else {
		MessageBox::Show(losingMessage);
	}
}

void MyForm::processValidWord(String^ value, Word^ newWord) {
	if (!this->isGuessRepeating(value)) {
		int pointValue = newWord->getPointValue();
		int coinsAwarded = newWord->getCoinsAwarded();
		this->guessedWordsBox->AppendText(" " + value + " (" + pointValue + ")" + Environment::NewLine);
		this->gc->incrementPlayerScore(pointValue);
		this->gc->incrementPlayerCoins(coinsAwarded);
		this->coinsLabel->Text = this->getCoinString();
		this->scoreLabel->Text = this->getScoreString();
	} else {
		MessageBox::Show(this->resourceManager->GetString(L"WordAlreadyGuessedOutput"));
	}
}

void MyForm::submitWord() {
	if (this->guessBox->Text->Length >= MIN_LETTER_LENGTH) {
		this->handleWordEntry();
	} else {
		MessageBox::Show(this->resourceManager->GetString(L"MustBeThreeLettersLongOutput"));
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

void MyForm::toggleBuyButtonsEnabled() {
	int coins = this->gc->getPlayerCoins();
	if (coins >= 2) {
		this->buy30SecondsButton->Enabled = true;
		this->generateButton->Enabled = true;
	} else {
		this->buy30SecondsButton->Enabled = false;
		this->generateButton->Enabled = false;
	}

	if (coins >= 3) {
		this->buy1MinuteButton->Enabled = true;
	} else {
		this->buy1MinuteButton->Enabled = false;
	}
}

void MyForm::beginNewGame() {
	String^ playerName = this->nameBox->Text;
	if (playerName->Contains("/")) {
		MessageBox::Show(this->resourceManager->GetString(L"InvalidNameOutput"));
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

		this->buy30SecondsButton->Enabled = false;
		this->buy1MinuteButton->Enabled = false;
		this->generateButton->Enabled = false;
	}
}

bool MyForm::isGuessRepeating(String^ guess) {
	return this->guessedWordsBox->Text->Contains(" " + guess + " ");
	}

void MyForm::showOptionsMenu() {
	OptionsDialog^ optionsDialog = gcnew OptionsDialog(this->userSetTimeLimit, this->reuseLetters);

	if (optionsDialog->ShowDialog() == ::DialogResult::OK) {
		::DialogResult dialogResult = MessageBox::Show(this->resourceManager->GetString(L"ResetQuestion"), this->resourceManager->GetString(L"ResetConfirm"), MessageBoxButtons::YesNo);
		if (dialogResult == ::DialogResult::Yes) {
			this->changeDefaultTime(optionsDialog);
			this->startNewGame();
		}
	}
}

void MyForm::changeDefaultTime(OptionsDialog^ optionsDialog) {
	this->reuseLetters = optionsDialog->getLetterReuse();
	this->minutesLeft = optionsDialog->getTimeLimit();
	this->userSetTimeLimit = optionsDialog->getTimeLimit();
}

System::Void MyForm::timer_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (this->minutesLeft > 0 || this->secondsLeft > 0)
    {
		this->formatClock(this->minutesLeft, this->secondsLeft);
    }
    else
    {
        this->endGame();
		MessageBox::Show(this->resourceManager->GetString(L"TimeUpOutput"));
    }
}

void MyForm::formatClock(int minutesLeft, int secondsLeft) {
	if(this->secondsLeft == 0) {
		this->minutesLeft = this->minutesLeft - 1;
		this->secondsLeft = 59;
	} else {
		this->secondsLeft = this->secondsLeft - 1;
	}

	if (this->secondsLeft < 10) {
		timerLabel->Text = this->minutesLeft + ":" + "0" + this->secondsLeft;
	} else if (this->secondsLeft == 0) {
		timerLabel->Text = this->minutesLeft + ":00";
	} else {
		timerLabel->Text = this->minutesLeft + ":" + this->secondsLeft;
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
	this->minutesLeft = this->userSetTimeLimit;
	this->secondsLeft = 0;
	this->enterName->Visible = true;

	HighScore^ highScore = gcnew HighScore(this->gc->getPlayer(), this->userSetTimeLimit);
	this->file->addHighScore(highScore);
}

}