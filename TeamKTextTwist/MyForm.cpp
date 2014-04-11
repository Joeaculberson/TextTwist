#include "MyForm.h"

using namespace System::Windows::Forms;
using namespace System::Text;

#include "FileIO.h"
using namespace model;

namespace Project1 {

System::Void MyForm::generateButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->gc = gcnew GameController();
	this->lettersBox->Text = gc->getRandomLetters(7);
}

System::Void MyForm::shuffleButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->lettersBox->Text != "") {
		String^ letters = this->lettersBox->Text;
		letters = this->gc->shuffleLetters(letters);
		this->lettersBox->Text = letters;
	} else {
		MessageBox::Show("There are no letters to shuffle at the moment. Please generate random letters first");
	}
}

System::Void MyForm::nameBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->nameBox->Text->Length != 0) {
		this->startButton->Enabled = true;
	} else {
		this->startButton->Enabled = false;
	}
}

System::Void MyForm::startButton_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ playerName = this->nameBox->Text;
	//this->gc->setPlayerName(playerName);
	this->generateButton->Enabled = true;
	this->shuffleButton->Enabled = true;
	this->submitButton->Enabled = true;
}

System::Void MyForm::submitButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->guessBox->Text->Length >= 3) {
		String^ value = this->guessBox->Text;
		Word^ newWord = gcnew Word(value);
		String^ allowedLetters = this->lettersBox->Text;
		if (this->gc->isWordValid(newWord, allowedLetters)) {
			int pointValue = newWord->getPointValue();
			this->guessedWords->AppendText(value + " (" + pointValue + ")" + "\n");
			this->gc->incrementPlayerScore(pointValue);
			String^ newAllowedLetters = this->removeCharacters(value, allowedLetters);
			this->lettersBox->Text = newAllowedLetters;
			this->scoreLabel->Text = this->gc->getPlayerScoreString();
		} else {
			MessageBox::Show("Word not allowed. You have lost one point.");
			this->gc->decrementPlayerScore();
			this->scoreLabel->Text = this->gc->getPlayerScoreString();
		}
	} else {
		MessageBox::Show("Your guess must be at least three letters long");
	}
	this->guessBox->Text = "";
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
}