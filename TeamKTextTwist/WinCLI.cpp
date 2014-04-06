#include "MyForm.h"

#include "Game.h"
using namespace controller;

using namespace Project1;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Game^ game = gcnew Game();
	game->run();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	Application::Run(gcnew MyForm());
	return 0;
}