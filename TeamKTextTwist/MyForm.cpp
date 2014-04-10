#include "MyForm.h"

#include "GameController.h"
using namespace controller;

using namespace System::Windows::Forms;
using namespace System::Text;

#include "FileIO.h"
using namespace model;

namespace Project1 {

System::Void MyForm::generateButton_Click(System::Object^  sender, System::EventArgs^  e) {
	FileIO^ file = gcnew FileIO();
	GameController^ gc = gcnew GameController(file->parseFile());
	this->randomLetters = gc->getRandomLetters(7);
	this->lettersBox->Text = this->randomLetters;
}
/**
 * Shuffles with the Fisher-Yates shuffle.
 */
System::Void MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Random^ random = gcnew Random();
	List<char>^ letters = gcnew List<char>();
	for (int i = 0; i < this->randomLetters->Length; i++) {
		letters->Add(this->randomLetters[i]);
	}

	for (int i = letters->Count; i > 1; i--)
	{
	    int j = random->Next(i);
	    char tmp = letters[j];
	    letters[j] = letters[i - 1];
	    letters[i - 1] = tmp;
	}
	StringBuilder^ sb = gcnew StringBuilder();
	for(int i = 0; i < this->randomLetters->Length; i++) {
		sb->Append(Char::ToString(letters[i]));
	}
	String^ val = sb->ToString();
	this->lettersBox->Text = val;
}

}