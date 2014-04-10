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

}