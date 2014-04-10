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

System::Void MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->lettersBox->Text = this->gc->shuffleLetters();
}

}