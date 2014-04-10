#include "MyForm.h"

using namespace System::Windows::Forms;
using namespace System::Text;

#include "FileIO.h"
using namespace model;

namespace Project1 {

System::Void MyForm::generateButton_Click(System::Object^  sender, System::EventArgs^  e) {
	FileIO^ file = gcnew FileIO();
	this->gc = gcnew GameController(file->parseFile());
	this->randomLetters = gc->getRandomLetters(7);
	this->lettersBox->Text = this->randomLetters;
}

System::Void MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->gc->shuffleLetters(this->randomLetters);
}

}