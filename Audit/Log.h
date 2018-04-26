#pragma once
#include <Windows.h>
#pragma comment(lib,"user32")

namespace Audit {

	using namespace System;
	using namespace System::Linq::Expressions;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;
	/// <summary>
	/// —водка дл€ Log
	/// </summary>
	public ref class Log : public System::Windows::Forms::Form
	{
	public:
		String ^ username;
		String ^ logpath;
		Log(String^ username, String^ logpath)
		{
			InitializeComponent();
			this->username = username;
			this->logpath = logpath;
		}
		DateTime gtime;
	private: System::Windows::Forms::PictureBox^  pictureBox_Camera;
	public:
		List<String^>^ gprlist;
		List<String^>^ bannedprlist;
		String^ logfile;
	private: System::Windows::Forms::Button^  button_LogPath;
	public:
	private: System::Windows::Forms::TextBox^  textBox_LogPath;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog;
	private: System::Windows::Forms::LinkLabel^  linkLabel_Report;
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Log()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button_Start;
	private: System::Windows::Forms::Button^  button_Pause;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Log::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button_Start = (gcnew System::Windows::Forms::Button());
			this->button_Pause = (gcnew System::Windows::Forms::Button());
			this->pictureBox_Camera = (gcnew System::Windows::Forms::PictureBox());
			this->linkLabel_Report = (gcnew System::Windows::Forms::LinkLabel());
			this->button_LogPath = (gcnew System::Windows::Forms::Button());
			this->textBox_LogPath = (gcnew System::Windows::Forms::TextBox());
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Camera))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Log::timer1_Tick);
			// 
			// button_Start
			// 
			this->button_Start->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_Start->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button_Start->FlatAppearance->BorderSize = 2;
			this->button_Start->Location = System::Drawing::Point(97, 12);
			this->button_Start->Name = L"button_Start";
			this->button_Start->Size = System::Drawing::Size(122, 33);
			this->button_Start->TabIndex = 0;
			this->button_Start->Text = L"start";
			this->button_Start->UseVisualStyleBackColor = true;
			this->button_Start->Click += gcnew System::EventHandler(this, &Log::button_Start_Click);
			// 
			// button_Pause
			// 
			this->button_Pause->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_Pause->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button_Pause->FlatAppearance->BorderSize = 2;
			this->button_Pause->Location = System::Drawing::Point(97, 51);
			this->button_Pause->Name = L"button_Pause";
			this->button_Pause->Size = System::Drawing::Size(122, 33);
			this->button_Pause->TabIndex = 1;
			this->button_Pause->Text = L"pause";
			this->button_Pause->UseVisualStyleBackColor = true;
			this->button_Pause->Click += gcnew System::EventHandler(this, &Log::button_Pause_Click);
			// 
			// pictureBox_Camera
			// 
			this->pictureBox_Camera->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_Camera.Image")));
			this->pictureBox_Camera->Location = System::Drawing::Point(-9, 2);
			this->pictureBox_Camera->Name = L"pictureBox_Camera";
			this->pictureBox_Camera->Size = System::Drawing::Size(100, 82);
			this->pictureBox_Camera->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_Camera->TabIndex = 2;
			this->pictureBox_Camera->TabStop = false;
			// 
			// linkLabel_Report
			// 
			this->linkLabel_Report->AutoSize = true;
			this->linkLabel_Report->Location = System::Drawing::Point(150, 144);
			this->linkLabel_Report->Name = L"linkLabel_Report";
			this->linkLabel_Report->Size = System::Drawing::Size(62, 13);
			this->linkLabel_Report->TabIndex = 3;
			this->linkLabel_Report->TabStop = true;
			this->linkLabel_Report->Text = L"View report";
			this->linkLabel_Report->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Log::linkLabel_Report_LinkClicked);
			// 
			// button_LogPath
			// 
			this->button_LogPath->Location = System::Drawing::Point(12, 90);
			this->button_LogPath->Name = L"button_LogPath";
			this->button_LogPath->Size = System::Drawing::Size(207, 23);
			this->button_LogPath->TabIndex = 4;
			this->button_LogPath->Text = L"Change log path";
			this->button_LogPath->UseVisualStyleBackColor = true;
			this->button_LogPath->Click += gcnew System::EventHandler(this, &Log::button_LogPath_Click);
			// 
			// textBox_LogPath
			// 
			this->textBox_LogPath->Location = System::Drawing::Point(12, 120);
			this->textBox_LogPath->Name = L"textBox_LogPath";
			this->textBox_LogPath->ReadOnly = true;
			this->textBox_LogPath->Size = System::Drawing::Size(207, 21);
			this->textBox_LogPath->TabIndex = 5;
			// 
			// Log
			// 
			this->AcceptButton = this->button_Start;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(224, 162);
			this->Controls->Add(this->textBox_LogPath);
			this->Controls->Add(this->button_LogPath);
			this->Controls->Add(this->linkLabel_Report);
			this->Controls->Add(this->pictureBox_Camera);
			this->Controls->Add(this->button_Pause);
			this->Controls->Add(this->button_Start);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Log";
			this->Text = L"Idle";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Log::Log_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Log::Log_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_Camera))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: List<String^>^ ToList(array<Process^>^ prarray) {
		List<String^>^ prlist = gcnew List<String^>();
		for each (Process^ process in prarray) {
			prlist->Add(process->ProcessName);
		}
		return prlist;
	}
	private: System::Void Log_Load(System::Object^  sender, System::EventArgs^  e) {
		if (username != "admin")
		{
			linkLabel_Report->Hide();
			button_LogPath->Hide();
			textBox_LogPath->Hide();
			this->Height = 125;
		}
		List<String^>^ lines = gcnew List<String^>(File::ReadLines("restrictions.txt"));
		bannedprlist = gcnew List<String^>();
		for each (String^ line in lines)
		{
			array<String^>^ strarr = line->Split(',');
			if (strarr[0] == username ||
				strarr[0] == "everyone") {
				bannedprlist->Add(strarr[1]);
			}
		}
		logfile = logpath + "log.txt";
		textBox_LogPath->Text = logfile;
		button_Pause->Enabled = false;
		gprlist = ToList(Process::GetProcesses());
		gtime = DateTime::Now;
		WriteTotxt(Environment::NewLine, logfile);
		WriteTotxt(String::Format("[{0}] ({1} logged in) ", gtime.ToString("MM\/dd\/yyyy HH:mm"), username), logfile);
	}
	private: System::Void button_Start_Click(System::Object^  sender, System::EventArgs^  e) {
		button_Start->Enabled = false;
		button_Pause->Enabled = true;
		button_Pause->Select();
		timer1->Start();
		Log::Text = "Logging...";
	}
	private: System::Void button_Pause_Click(System::Object^  sender, System::EventArgs^  e) {
		button_Start->Enabled = true;
		button_Pause->Enabled = false;
		button_Start->Select();
		this->AcceptButton = button_Start;
		timer1->Stop();
		Log::Text = "Idle";
	}
	private: void WriteTotxt(String^ value, String^ path)
	{
		StreamWriter^ stream = gcnew StreamWriter(path, true);
		stream->Write(value);
		stream->Close();
	}
	private: String ^ TimeStamp() {
		DateTime dtime = DateTime::Now;
		if (gtime.Day != dtime.Day ||
			gtime.Month != dtime.Month ||
			gtime.Year != dtime.Year ||
			gtime.Hour != dtime.Hour ||
			gtime.Minute != dtime.Minute) {
			gtime = dtime;
			return String::Format("{0}[{1}] ", Environment::NewLine, gtime.ToString("MM\/dd\/yyyy HH:mm"));
		}
		else return "";
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		String^ buffer = "";
		for each(System::Int32 i in Enum::GetValues(Keys::typeid))
		{
			DateTime dtime = DateTime::Now;
			if (GetAsyncKeyState(i) == -32767) {
				buffer += TimeStamp();
				buffer += Enum::GetName(Keys::typeid, i);
				buffer += " ";
			}
		}
		List<String^>^ prlist = ToList(Process::GetProcesses());
		List<String^>^ diff = gcnew List<String^>(System::Linq::Enumerable::Except(prlist, gprlist));
		if (diff->Count != 0) {
			for each (String^ pr in diff) {
				if (bannedprlist->Contains(pr)) {
					WriteTotxt(
						String::Format("{0}{1} ({2} opened {3}!)", 
							Environment::NewLine, 
							gtime.ToString("MM\/dd\/yyyy HH:mm:ss"), 
							username, 
							pr), 
						"report.txt");
				}
			}
			buffer += TimeStamp();
			buffer += String::Format("({0} opened) ", String::Join(" opened) (", diff));
			gprlist = prlist;
		}
		WriteTotxt(buffer, logfile);
	}
	private: System::Void Log_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		WriteTotxt(TimeStamp(), logfile);
		WriteTotxt(String::Format("({0} logged out) ", username), logfile);
	}
	private: System::Void linkLabel_Report_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
		Process::Start("report.txt");
	}
	private: System::Void button_LogPath_Click(System::Object^  sender, System::EventArgs^  e) {
		folderBrowserDialog->ShowDialog();
		logpath = folderBrowserDialog->SelectedPath;
		logfile = logpath + "log.txt";
		textBox_LogPath->Text = logfile;
	}
};
}
