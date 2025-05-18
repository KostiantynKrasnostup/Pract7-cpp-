#pragma once

namespace PR77 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblLogin;
	private: System::Windows::Forms::TextBox^ txtLogin;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnGeneratePassword;
	private: System::Windows::Forms::Label^ lblGeneratedPassword;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblLogin = (gcnew System::Windows::Forms::Label());
			this->txtLogin = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnGeneratePassword = (gcnew System::Windows::Forms::Button());
			this->lblGeneratedPassword = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblLogin
			// 
			this->lblLogin->AutoSize = true;
			this->lblLogin->Location = System::Drawing::Point(106, 24);
			this->lblLogin->Name = L"lblLogin";
			this->lblLogin->Size = System::Drawing::Size(44, 16);
			this->lblLogin->TabIndex = 0;
			this->lblLogin->Text = L"Логін:";
			// 
			// txtLogin
			// 
			this->txtLogin->Location = System::Drawing::Point(109, 43);
			this->txtLogin->Name = L"txtLogin";
			this->txtLogin->Size = System::Drawing::Size(146, 22);
			this->txtLogin->TabIndex = 1;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(137, 86);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(59, 16);
			this->lblPassword->TabIndex = 2;
			this->lblPassword->Text = L"Пароль:";
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(109, 105);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(146, 22);
			this->txtPassword->TabIndex = 3;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(153, 145);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 4;
			this->btnLogin->Text = L"Увійти";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MyForm::btnLogin_Click);
			// 
			// btnGeneratePassword
			// 
			this->btnGeneratePassword->Location = System::Drawing::Point(109, 174);
			this->btnGeneratePassword->Name = L"btnGeneratePassword";
			this->btnGeneratePassword->Size = System::Drawing::Size(164, 23);
			this->btnGeneratePassword->TabIndex = 5;
			this->btnGeneratePassword->Text = L"Згенерувати пароль";
			this->btnGeneratePassword->UseVisualStyleBackColor = true;
			this->btnGeneratePassword->Click += gcnew System::EventHandler(this, &MyForm::btnGeneratePassword_Click);
			// 
			// lblGeneratedPassword
			// 
			this->lblGeneratedPassword->AutoSize = true;
			this->lblGeneratedPassword->Location = System::Drawing::Point(78, 216);
			this->lblGeneratedPassword->Name = L"lblGeneratedPassword";
			this->lblGeneratedPassword->Size = System::Drawing::Size(0, 16);
			this->lblGeneratedPassword->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(376, 253);
			this->Controls->Add(this->lblGeneratedPassword);
			this->Controls->Add(this->btnGeneratePassword);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->txtLogin);
			this->Controls->Add(this->lblLogin);
			this->Name = L"MyForm";
			this->Text = L"Авторизація користувача";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		  private:

			  String^ GeneratePassword(int length) {
				  String^ upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				  String^ lower = "abcdefghijklmnopqrstuvwxyz";
				  String^ digits = "0123456789";
				  String^ special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

				  String^ all = upper + lower + digits + special;
				  String^ password = "";

				  Random^ rand = gcnew Random();

				  password += upper[rand->Next(upper->Length)];
				  password += lower[rand->Next(lower->Length)];
				  password += digits[rand->Next(digits->Length)];
				  password += special[rand->Next(special->Length)];

				  for (int i = 4; i < length; i++)
					  password += all[rand->Next(all->Length)];

				  return password;
			  }
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ login = txtLogin->Text;
			String^ password = txtPassword->Text;


			if (!System::Text::RegularExpressions::Regex::IsMatch(
				login,
				"^(?=.*[A-Z])(?=.*\\d)(?=.*[^a-zA-Z0-9])[A-Za-z\\d!@#$%^&*()_+\\-=\\[\\]{}|;:'\",.<>/?]{8,}$"
			))

				throw gcnew System::Exception("Логін має містити щонайменше одну велику літеру, одну цифру, один спецсимвол, лише англійські літери та бути не менше 8 символів.");


			int categories = 0;
			if (System::Text::RegularExpressions::Regex::IsMatch(password, "[A-Z]")) categories++;
			if (System::Text::RegularExpressions::Regex::IsMatch(password, "[a-z]")) categories++;
			if (System::Text::RegularExpressions::Regex::IsMatch(password, "[0-9]")) categories++;
			if (System::Text::RegularExpressions::Regex::IsMatch(password, "[^a-zA-Z0-9]")) categories++;

			if (password->Length < 8 || categories < 3)
				throw gcnew System::Exception("Пароль повинен містити принаймні 3 з 4 категорій символів (великі, малі, цифри, спецсимволи) і бути довжиною не менше 8 символів.");

			MessageBox::Show("Авторизація успішна!");
		}
		catch (System::Exception^ ex) {
			MessageBox::Show("Помилка: " + ex->Message);
		}
	}
private: System::Void btnGeneratePassword_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ pass = GeneratePassword(12);


		txtPassword->Text = pass;
		lblGeneratedPassword->Text = "Згенеровано: " + pass;
	}
	catch (System::Exception^ ex) {
		MessageBox::Show("Помилка генерації: " + ex->Message);
	}
}
};
}
