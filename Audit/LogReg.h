#pragma once
#include "Log.h"
namespace Audit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Text;
	using namespace System::Drawing;
	using namespace System::Security::Cryptography;

	/// <summary>
	/// —водка дл€ LogReg
	/// </summary>
	public ref class LogReg : public System::Windows::Forms::Form
	{
	public:
		LogReg(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	public:
		static String^ LogPath = System::IO::Directory::GetCurrentDirectory() + "\\";
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~LogReg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox_Username;
	protected:
	private: System::Windows::Forms::TextBox^  textBox_Password;
	private: System::Windows::Forms::Label^  label_Username;
	private: System::Windows::Forms::Label^  label_Password;
	private: System::Windows::Forms::Button^  button_Login;
	private: System::Windows::Forms::Button^  button_Register;
	private: System::Windows::Forms::PictureBox^  pictureBox_logreg;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LogReg::typeid));
			this->textBox_Username = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Password = (gcnew System::Windows::Forms::TextBox());
			this->label_Username = (gcnew System::Windows::Forms::Label());
			this->label_Password = (gcnew System::Windows::Forms::Label());
			this->button_Login = (gcnew System::Windows::Forms::Button());
			this->button_Register = (gcnew System::Windows::Forms::Button());
			this->pictureBox_logreg = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_logreg))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox_Username
			// 
			this->textBox_Username->Location = System::Drawing::Point(173, 12);
			this->textBox_Username->Name = L"textBox_Username";
			this->textBox_Username->Size = System::Drawing::Size(202, 21);
			this->textBox_Username->TabIndex = 0;
			// 
			// textBox_Password
			// 
			this->textBox_Password->Location = System::Drawing::Point(173, 40);
			this->textBox_Password->Name = L"textBox_Password";
			this->textBox_Password->Size = System::Drawing::Size(202, 21);
			this->textBox_Password->TabIndex = 1;
			this->textBox_Password->UseSystemPasswordChar = true;
			// 
			// label_Username
			// 
			this->label_Username->AutoSize = true;
			this->label_Username->Location = System::Drawing::Point(112, 16);
			this->label_Username->Name = L"label_Username";
			this->label_Username->Size = System::Drawing::Size(55, 13);
			this->label_Username->TabIndex = 2;
			this->label_Username->Text = L"Username";
			// 
			// label_Password
			// 
			this->label_Password->AutoSize = true;
			this->label_Password->Location = System::Drawing::Point(112, 43);
			this->label_Password->Name = L"label_Password";
			this->label_Password->Size = System::Drawing::Size(53, 13);
			this->label_Password->TabIndex = 3;
			this->label_Password->Text = L"Password";
			// 
			// button_Login
			// 
			this->button_Login->Location = System::Drawing::Point(112, 67);
			this->button_Login->Name = L"button_Login";
			this->button_Login->Size = System::Drawing::Size(128, 23);
			this->button_Login->TabIndex = 2;
			this->button_Login->Text = L"Login";
			this->button_Login->UseVisualStyleBackColor = true;
			this->button_Login->Click += gcnew System::EventHandler(this, &LogReg::button_Login_Click);
			// 
			// button_Register
			// 
			this->button_Register->Location = System::Drawing::Point(246, 67);
			this->button_Register->Name = L"button_Register";
			this->button_Register->Size = System::Drawing::Size(128, 23);
			this->button_Register->TabIndex = 3;
			this->button_Register->Text = L"Register";
			this->button_Register->UseVisualStyleBackColor = true;
			this->button_Register->Click += gcnew System::EventHandler(this, &LogReg::button_Register_Click);
			// 
			// pictureBox_logreg
			// 
			this->pictureBox_logreg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_logreg.Image")));
			this->pictureBox_logreg->Location = System::Drawing::Point(13, 14);
			this->pictureBox_logreg->Name = L"pictureBox_logreg";
			this->pictureBox_logreg->Size = System::Drawing::Size(90, 78);
			this->pictureBox_logreg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_logreg->TabIndex = 4;
			this->pictureBox_logreg->TabStop = false;
			// 
			// LogReg
			// 
			this->AcceptButton = this->button_Login;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(389, 104);
			this->Controls->Add(this->pictureBox_logreg);
			this->Controls->Add(this->button_Register);
			this->Controls->Add(this->button_Login);
			this->Controls->Add(this->label_Password);
			this->Controls->Add(this->label_Username);
			this->Controls->Add(this->textBox_Password);
			this->Controls->Add(this->textBox_Username);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"LogReg";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_logreg))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: String^ getMD5String(String^ inputString)
	{
		array<Byte>^ byteArray = Encoding::ASCII->GetBytes(inputString);
		MD5CryptoServiceProvider^ md5provider = gcnew MD5CryptoServiceProvider();
		array<Byte>^ byteArrayHash = md5provider->ComputeHash(byteArray);
		return BitConverter::ToString(byteArrayHash);
	}
	private: System::Void button_Login_Click(System::Object^  sender, System::EventArgs^  e) {
		for each (String^ line in File::ReadLines("users.txt"))
		{
			if (line->Contains(textBox_Username->Text))
			{
				String^ pass = line->Replace(textBox_Username->Text + ",", "");
				if (getMD5String(textBox_Password->Text) != pass) {
					MessageBox::Show(this, "Wrong username or password", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
					
				}
				else {
					Log^ log = gcnew Log(textBox_Username->Text, LogPath);
					log->Owner = this;
					this->Hide();
					log->ShowDialog();
					LogPath = log->logpath;
					this->Show();
					return;
				}
			}
		}
		MessageBox::Show(this, "Wrong username or password", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
		
	}
	private: System::Void button_Register_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBox_Username->Text == "everyone") {
			MessageBox::Show(this, "Username ""everyone"" is not allowed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		List<String^>^ lines = gcnew List<String^>(File::ReadLines("users.txt"));
		for each (String^ line in lines)
		{
			if (line->Contains(textBox_Username->Text))
			{
				MessageBox::Show(this, "Username is already taken", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
		}
		File::AppendAllText("users.txt",String::Format("{0}{1},{2}",
			Environment::NewLine,
			textBox_Username->Text,
			getMD5String(textBox_Password->Text)));
		Log^ log = gcnew Log(textBox_Username->Text, LogPath);
		log->Owner = this;
		this->Hide();
		log->ShowDialog();
		LogPath = log->logpath;
		this->Show();
		return;
	}
	};
}
