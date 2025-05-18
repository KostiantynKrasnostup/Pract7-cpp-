#pragma once

namespace PR7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();

			if (System::ComponentModel::LicenseManager::UsageMode ==
				System::ComponentModel::LicenseUsageMode::Designtime)
				return;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelPrompt;
	private: System::Windows::Forms::TextBox^ textBoxX;
	private: System::Windows::Forms::Label^ labelResult;
	protected:

	protected:


	private: System::Windows::Forms::Button^ buttonCalc;


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
			this->labelPrompt = (gcnew System::Windows::Forms::Label());
			this->textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->buttonCalc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelPrompt
			// 
			this->labelPrompt->AutoSize = true;
			this->labelPrompt->Location = System::Drawing::Point(249, 30);
			this->labelPrompt->Name = L"labelPrompt";
			this->labelPrompt->Size = System::Drawing::Size(69, 16);
			this->labelPrompt->TabIndex = 0;
			this->labelPrompt->Text = L"Введіть x:";
			// 
			// textBoxX
			// 
			this->textBoxX->Location = System::Drawing::Point(230, 66);
			this->textBoxX->Name = L"textBoxX";
			this->textBoxX->Size = System::Drawing::Size(100, 22);
			this->textBoxX->TabIndex = 1;
			// 
			// labelResult
			// 
			this->labelResult->AutoSize = true;
			this->labelResult->Location = System::Drawing::Point(258, 181);
			this->labelResult->Name = L"labelResult";
			this->labelResult->Size = System::Drawing::Size(0, 16);
			this->labelResult->TabIndex = 2;
			// 
			// buttonCalc
			// 
			this->buttonCalc->Location = System::Drawing::Point(243, 119);
			this->buttonCalc->Name = L"buttonCalc";
			this->buttonCalc->Size = System::Drawing::Size(75, 23);
			this->buttonCalc->TabIndex = 3;
			this->buttonCalc->Text = L"Обчислити";
			this->buttonCalc->UseVisualStyleBackColor = true;
			this->buttonCalc->Click += gcnew System::EventHandler(this, &MyForm1::buttonCalc_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(545, 384);
			this->Controls->Add(this->buttonCalc);
			this->Controls->Add(this->labelResult);
			this->Controls->Add(this->textBoxX);
			this->Controls->Add(this->labelPrompt);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCalc_Click(System::Object^ sender, System::EventArgs^ e) {
		double x;
		if (Double::TryParse(textBoxX->Text, x))
		{
			double y;

			if (x >= 2)
			{
				y = 3 * Math::Exp(x) + 5 * x;
			}
			else
			{
				double underRoot = 8 - Math::Pow(x, 3);
				if (underRoot < 0)
				{
					labelResult->Text = "Помилка: корінь з від’ємного числа!";
					return;
				}
				y = Math::Sqrt(underRoot);
			}

			labelResult->Text = "y = " + y.ToString("F4");
		}
		else
		{
			labelResult->Text = "Некоректне значення x!";
		}

	}
};
}
