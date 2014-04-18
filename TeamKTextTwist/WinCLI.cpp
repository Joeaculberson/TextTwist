#include "MyForm.h"

using namespace controller;

/// <summary>
/// The entry point for the program.
/// </summary>
/// <pre>None.</pre>
/// <param value="args">Not used.</param>
/// <return>0</return>
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	Application::Run(gcnew MyForm());
	return 0;
}