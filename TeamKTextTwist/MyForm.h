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
			this->timeLimit = DEFAULT_TIME_LIMIT;
			this->reuseLetters = false;
			this->gc = gcnew GameController();
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
	private: System::Windows::Forms::TextBox^  guessBox;

	private: System::Windows::Forms::TextBox^  lettersBox;
	private: System::Windows::Forms::TextBox^  guessedWords;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  shuffleButton;
	private: System::Windows::Forms::Button^  submitButton;
	private: System::Windows::Forms::Label^  namePrompt;
	private: System::Windows::Forms::TextBox^  nameBox;
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::Label^  scoreLabel;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  highScoresToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;

	private: GameController^ gc;
	private: int timeLimit;
	private: bool reuseLetters;
	private: System::Windows::Forms::Button^  clearAllButton;
	private: System::Windows::Forms::Button^  newGameButton;
	private: int static const DEFAULT_TIME_LIMIT = 1;

	private: System::Void generateButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void shuffleButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void nameBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void submitButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: String^ removeCharacters(String^ ofWord, String^ fromString);
	private: void startNewGame();
	private: System::Void optionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void newGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void highScoresToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void clearAllButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void newGameButton_Click(System::Object^  sender, System::EventArgs^  e);

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
			this->guessBox = (gcnew System::Windows::Forms::TextBox());
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->lettersBox = (gcnew System::Windows::Forms::TextBox());
			this->guessedWords = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->shuffleButton = (gcnew System::Windows::Forms::Button());
			this->namePrompt = (gcnew System::Windows::Forms::Label());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->scoreLabel = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->highScoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearAllButton = (gcnew System::Windows::Forms::Button());
			this->newGameButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// generateButton
			// 
			this->generateButton->Enabled = false;
			this->generateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->generateButton->Location = System::Drawing::Point(324, 354);
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
			this->lettersLabel->Location = System::Drawing::Point(354, 40);
			this->lettersLabel->Name = L"lettersLabel";
			this->lettersLabel->Size = System::Drawing::Size(189, 17);
			this->lettersLabel->TabIndex = 1;
			this->lettersLabel->Text = L"The letters you may use are:";
			// 
			// guessBox
			// 
			this->guessBox->Location = System::Drawing::Point(372, 329);
			this->guessBox->Margin = System::Windows::Forms::Padding(2);
			this->guessBox->Name = L"guessBox";
			this->guessBox->Size = System::Drawing::Size(149, 20);
			this->guessBox->TabIndex = 3;
			// 
			// submitButton
			// 
			this->submitButton->Enabled = false;
			this->submitButton->Location = System::Drawing::Point(525, 329);
			this->submitButton->Margin = System::Windows::Forms::Padding(2);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(79, 21);
			this->submitButton->TabIndex = 4;
			this->submitButton->Text = L"Submit";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &MyForm::submitButton_Click);
			// 
			// lettersBox
			// 
			this->lettersBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lettersBox->Location = System::Drawing::Point(309, 76);
			this->lettersBox->Multiline = true;
			this->lettersBox->Name = L"lettersBox";
			this->lettersBox->ReadOnly = true;
			this->lettersBox->Size = System::Drawing::Size(268, 55);
			this->lettersBox->TabIndex = 2;
			this->lettersBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// guessedWords
			// 
			this->guessedWords->Location = System::Drawing::Point(309, 172);
			this->guessedWords->Margin = System::Windows::Forms::Padding(2);
			this->guessedWords->Multiline = true;
			this->guessedWords->Name = L"guessedWords";
			this->guessedWords->ReadOnly = true;
			this->guessedWords->Size = System::Drawing::Size(268, 151);
			this->guessedWords->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(354, 144);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Correctly guessed words:";
			// 
			// shuffleButton
			// 
			this->shuffleButton->Enabled = false;
			this->shuffleButton->Location = System::Drawing::Point(277, 327);
			this->shuffleButton->Margin = System::Windows::Forms::Padding(2);
			this->shuffleButton->Name = L"shuffleButton";
			this->shuffleButton->Size = System::Drawing::Size(91, 22);
			this->shuffleButton->TabIndex = 7;
			this->shuffleButton->Text = L"Shuffle Letters";
			this->shuffleButton->UseVisualStyleBackColor = true;
			this->shuffleButton->Click += gcnew System::EventHandler(this, &MyForm::shuffleButton_Click);
			// 
			// namePrompt
			// 
			this->namePrompt->AutoSize = true;
			this->namePrompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->namePrompt->Location = System::Drawing::Point(34, 76);
			this->namePrompt->Name = L"namePrompt";
			this->namePrompt->Size = System::Drawing::Size(235, 17);
			this->namePrompt->TabIndex = 8;
			this->namePrompt->Text = L"Please enter a Player name to start:";
			// 
			// nameBox
			// 
			this->nameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->nameBox->Location = System::Drawing::Point(37, 106);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(100, 23);
			this->nameBox->TabIndex = 9;
			this->nameBox->TextChanged += gcnew System::EventHandler(this, &MyForm::nameBox_TextChanged);
			// 
			// startButton
			// 
			this->startButton->Enabled = false;
			this->startButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->startButton->Location = System::Drawing::Point(172, 96);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(75, 35);
			this->startButton->TabIndex = 10;
			this->startButton->Text = L"Begin";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &MyForm::startButton_Click);
			// 
			// scoreLabel
			// 
			this->scoreLabel->AutoSize = true;
			this->scoreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->scoreLabel->Location = System::Drawing::Point(34, 154);
			this->scoreLabel->Name = L"scoreLabel";
			this->scoreLabel->Size = System::Drawing::Size(61, 17);
			this->scoreLabel->TabIndex = 11;
			this->scoreLabel->Text = L"Score: 0";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(615, 24);
			this->menuStrip1->TabIndex = 12;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->newGameToolStripMenuItem, 
				this->highScoresToolStripMenuItem, this->optionsToolStripMenuItem, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 22);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->newGameToolStripMenuItem->Text = L"New Game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newGameToolStripMenuItem_Click);
			// 
			// highScoresToolStripMenuItem
			// 
			this->highScoresToolStripMenuItem->Name = L"highScoresToolStripMenuItem";
			this->highScoresToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->highScoresToolStripMenuItem->Text = L"High Scores";
			this->highScoresToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::highScoresToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->optionsToolStripMenuItem->Text = L"Options";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::optionsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// clearAllButton
			// 
			this->clearAllButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->clearAllButton->Location = System::Drawing::Point(447, 354);
			this->clearAllButton->Name = L"clearAllButton";
			this->clearAllButton->Size = System::Drawing::Size(98, 25);
			this->clearAllButton->TabIndex = 13;
			this->clearAllButton->Text = L"Clear Guess";
			this->clearAllButton->UseVisualStyleBackColor = true;
			this->clearAllButton->Click += gcnew System::EventHandler(this, &MyForm::clearAllButton_Click);
			// 
			// newGameButton
			// 
			this->newGameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->newGameButton->Location = System::Drawing::Point(62, 224);
			this->newGameButton->Name = L"newGameButton";
			this->newGameButton->Size = System::Drawing::Size(112, 44);
			this->newGameButton->TabIndex = 14;
			this->newGameButton->Text = L"New Game";
			this->newGameButton->UseVisualStyleBackColor = true;
			this->newGameButton->Click += gcnew System::EventHandler(this, &MyForm::newGameButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(615, 389);
			this->Controls->Add(this->newGameButton);
			this->Controls->Add(this->clearAllButton);
			this->Controls->Add(this->scoreLabel);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->namePrompt);
			this->Controls->Add(this->shuffleButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->guessedWords);
			this->Controls->Add(this->submitButton);
			this->Controls->Add(this->guessBox);
			this->Controls->Add(this->lettersBox);
			this->Controls->Add(this->lettersLabel);
			this->Controls->Add(this->generateButton);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Text Twist by Ayaan Kazerouni and Joe Culberson";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
