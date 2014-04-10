#include "MyForm.h"

#include "GameController.h"
using namespace controller;

using namespace System::Windows::Forms;

#include "FileIO.h"
using namespace model;

namespace Project1 {
void MyForm::generateButton_Click(System::Object^  sender, System::EventArgs^  e) {
	FileIO^ file = gcnew FileIO();
	GameController^ gc = gcnew GameController(file->parseFile());
	MessageBox::Show(gc->getRandomLetters(7));
		 
}
}