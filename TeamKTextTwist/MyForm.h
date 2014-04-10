#pragma once

#include "GameController.h"
using namespace model;

namespace Project1 {

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
	private: System::Windows::Forms::Button^  generateButton;
	protected: 
	private: System::Windows::Forms::Label^  lettersLabel;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  lettersBox;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  shuffleButton;

	private: System::Windows::Forms::Button^  button1;
	private: GameController^ gc;




	private: System::Void generateButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void shuffleButton_Click(System::Object^  sender, System::EventArgs^  e);

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
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->lettersLabel = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lettersBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->shuffleButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// generateButton
			// 
			this->generateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->generateButton->Location = System::Drawing::Point(199, 332);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(117, 25);
			this->generateButton->TabIndex = 0;
			this->generateButton->TabStop = false;
			this->generateButton->Text = L"Generate Letters!";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &MyForm::generateButton_Click);
			// 
			// lettersLabel
			// 
			this->lettersLabel->AutoSize = true;
			this->lettersLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lettersLabel->Location = System::Drawing::Point(189, 6);
			this->lettersLabel->Name = L"lettersLabel";
			this->lettersLabel->Size = System::Drawing::Size(189, 17);
			this->lettersLabel->TabIndex = 1;
			this->lettersLabel->Text = L"The letters you may use are:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(183, 310);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(149, 20);
			this->textBox1->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(335, 309);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 21);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// lettersBox
			// 
			this->lettersBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lettersBox->Location = System::Drawing::Point(139, 25);
			this->lettersBox->Multiline = true;
			this->lettersBox->Name = L"lettersBox";
			this->lettersBox->ReadOnly = true;
			this->lettersBox->Size = System::Drawing::Size(268, 55);
			this->lettersBox->TabIndex = 2;
			this->lettersBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(139, 132);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(268, 151);
			this->textBox2->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(207, 117);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Correctly guessed words:";
			// 
			// shuffleButton
			// 
			this->shuffleButton->Location = System::Drawing::Point(87, 307);
			this->shuffleButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->shuffleButton->Name = L"shuffleButton";
			this->shuffleButton->Size = System::Drawing::Size(91, 22);
			this->shuffleButton->TabIndex = 7;
			this->shuffleButton->Text = L"Shuffle Letters";
			this->shuffleButton->UseVisualStyleBackColor = true;
			this->shuffleButton->Click += gcnew System::EventHandler(this, &MyForm::shuffleButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 365);
			this->Controls->Add(this->shuffleButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->lettersBox);
			this->Controls->Add(this->lettersLabel);
			this->Controls->Add(this->generateButton);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"Text Twist by Ayaan Kazerouni and Joe Culberson";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
