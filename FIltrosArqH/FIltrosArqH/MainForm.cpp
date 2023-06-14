#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;


int main(void) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew FIltrosArqH::MainForm);
	return 0;
}

