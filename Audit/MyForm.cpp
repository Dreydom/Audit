#include "LogReg.h"

using namespace System;
using namespace System::Threading;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<String^>^ args) {
	bool createdNew;
	Mutex^ m = gcnew Mutex(true, "Audit", createdNew);
	if (!createdNew) {
		MessageBox::Show("Already running!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Audit::LogReg form;
	Application::Run(%form);
}