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
			this->userSetTimeLimit = DEFAULT_TIME_LIMIT;
			this->secondsLeft = 0;
			this->timerLabel->Text = this->timeLimit + ":00";
			this->reuseLetters = false;
			this->newGameButton->Focus();
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

	protected: 
	private: System::Windows::Forms::Label^  lettersLabel;
	private: System::Windows::Forms::TextBox^  guessBox;

	private: System::Windows::Forms::TextBox^  lettersBox;
	private: System::Windows::Forms::TextBox^  guessedWordsBox;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  shuffleButton;
	private: System::Windows::Forms::Button^  submitButton;

	private: System::Windows::Forms::TextBox^  nameBox;
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::Label^  scoreLabel;
	private: System::Windows::Forms::MenuStrip^  menuBar;

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  highScoresToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;

	private: GameController^ gc;
	private: FileIO^ file;
	private: int secondsLeft;
	private: int timeLimit;
	private: bool reuseLetters;
	private: System::Windows::Forms::Button^  clearAllButton;
	private: System::Windows::Forms::Button^  newGameButton;
	private: int static const DEFAULT_TIME_LIMIT = 1;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Label^  timerLabel;
	private: int static const MIN_LETTER_LENGTH = 3;
	private: int userSetTimeLimit;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  enterName;
	private: String^ generatedLetters;

	private: System::Void shuffleButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void nameBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void submitButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: void startNewGame();
	private: void handleWordEntry();
	private: void submitWord();
	private: void handleGenerateEvent();
	private: void handleShuffle();
	private: void toggleStartButtonEnabled();
	private: void beginNewGame();
	private: void showOptionsMenu();
	private: System::Void optionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void newGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void highScoresToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void clearAllButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void newGameButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lettersBox_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void guessedWordsBox_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::ComponentModel::IContainer^  components;
	private: void MyForm::endGame();

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lettersLabel = (gcnew System::Windows::Forms::Label());
			this->guessBox = (gcnew System::Windows::Forms::TextBox());
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->lettersBox = (gcnew System::Windows::Forms::TextBox());
			this->guessedWordsBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->shuffleButton = (gcnew System::Windows::Forms::Button());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->scoreLabel = (gcnew System::Windows::Forms::Label());
			this->menuBar = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->highScoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearAllButton = (gcnew System::Windows::Forms::Button());
			this->newGameButton = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->enterName = (gcnew System::Windows::Forms::Label());
			this->menuBar->SuspendLayout();
			this->SuspendLayout();
			// 
			// lettersLabel
			// 
			this->lettersLabel->AutoSize = true;
			this->lettersLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lettersLabel->Location = System::Drawing::Point(261, 320);
			this->lettersLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lettersLabel->Name = L"lettersLabel";
			this->lettersLabel->Size = System::Drawing::Size(314, 29);
			this->lettersLabel->TabIndex = 1;
			this->lettersLabel->Text = L"The letters you may use are:";
			// 
			// guessBox
			// 
			this->guessBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->guessBox->Location = System::Drawing::Point(224, 452);
			this->guessBox->Name = L"guessBox";
			this->guessBox->Size = System::Drawing::Size(400, 39);
			this->guessBox->TabIndex = 3;
			// 
			// submitButton
			// 
			this->submitButton->Enabled = false;
			this->submitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->submitButton->Location = System::Drawing::Point(631, 450);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(127, 41);
			this->submitButton->TabIndex = 4;
			this->submitButton->Text = L"Submit";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &MyForm::submitButton_Click);
			// 
			// lettersBox
			// 
			this->lettersBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lettersBox->Location = System::Drawing::Point(224, 354);
			this->lettersBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->lettersBox->Multiline = true;
			this->lettersBox->Name = L"lettersBox";
			this->lettersBox->ReadOnly = true;
			this->lettersBox->Size = System::Drawing::Size(400, 82);
			this->lettersBox->TabIndex = 2;
			this->lettersBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->lettersBox->Click += gcnew System::EventHandler(this, &MyForm::lettersBox_Click);
			// 
			// guessedWordsBox
			// 
			this->guessedWordsBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->guessedWordsBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->guessedWordsBox->Location = System::Drawing::Point(224, 81);
			this->guessedWordsBox->Multiline = true;
			this->guessedWordsBox->Name = L"guessedWordsBox";
			this->guessedWordsBox->ReadOnly = true;
			this->guessedWordsBox->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->guessedWordsBox->Size = System::Drawing::Size(400, 230);
			this->guessedWordsBox->TabIndex = 5;
			this->guessedWordsBox->Click += gcnew System::EventHandler(this, &MyForm::guessedWordsBox_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(271, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(286, 29);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Correctly guessed words:";
			// 
			// shuffleButton
			// 
			this->shuffleButton->Enabled = false;
			this->shuffleButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->shuffleButton->Location = System::Drawing::Point(428, 505);
			this->shuffleButton->Name = L"shuffleButton";
			this->shuffleButton->Size = System::Drawing::Size(180, 39);
			this->shuffleButton->TabIndex = 7;
			this->shuffleButton->Text = L"Shuffle Letters";
			this->shuffleButton->UseVisualStyleBackColor = true;
			this->shuffleButton->Click += gcnew System::EventHandler(this, &MyForm::shuffleButton_Click);
			// 
			// nameBox
			// 
			this->nameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->nameBox->Location = System::Drawing::Point(224, 452);
			this->nameBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(399, 39);
			this->nameBox->TabIndex = 9;
			this->nameBox->TextChanged += gcnew System::EventHandler(this, &MyForm::nameBox_TextChanged);
			// 
			// startButton
			// 
			this->startButton->Enabled = false;
			this->startButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->startButton->Location = System::Drawing::Point(631, 450);
			this->startButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(127, 41);
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
			this->scoreLabel->Location = System::Drawing::Point(695, 39);
			this->scoreLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->scoreLabel->Name = L"scoreLabel";
			this->scoreLabel->Size = System::Drawing::Size(86, 25);
			this->scoreLabel->TabIndex = 11;
			this->scoreLabel->Text = L"Score: 0";
			// 
			// menuBar
			// 
			this->menuBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuBar->Location = System::Drawing::Point(0, 0);
			this->menuBar->Name = L"menuBar";
			this->menuBar->Size = System::Drawing::Size(794, 33);
			this->menuBar->TabIndex = 12;
			this->menuBar->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->newGameToolStripMenuItem, 
				this->highScoresToolStripMenuItem, this->optionsToolStripMenuItem, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(50, 29);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(179, 30);
			this->newGameToolStripMenuItem->Text = L"New Game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newGameToolStripMenuItem_Click);
			// 
			// highScoresToolStripMenuItem
			// 
			this->highScoresToolStripMenuItem->Name = L"highScoresToolStripMenuItem";
			this->highScoresToolStripMenuItem->Size = System::Drawing::Size(179, 30);
			this->highScoresToolStripMenuItem->Text = L"High Scores";
			this->highScoresToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::highScoresToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(179, 30);
			this->optionsToolStripMenuItem->Text = L"Options";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::optionsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(179, 30);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// clearAllButton
			// 
			this->clearAllButton->Enabled = false;
			this->clearAllButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->clearAllButton->Location = System::Drawing::Point(241, 505);
			this->clearAllButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->clearAllButton->Name = L"clearAllButton";
			this->clearAllButton->Size = System::Drawing::Size(180, 39);
			this->clearAllButton->TabIndex = 13;
			this->clearAllButton->Text = L"Clear Guess";
			this->clearAllButton->UseVisualStyleBackColor = true;
			this->clearAllButton->Click += gcnew System::EventHandler(this, &MyForm::clearAllButton_Click);
			// 
			// newGameButton
			// 
			this->newGameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->newGameButton->Location = System::Drawing::Point(654, 78);
			this->newGameButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->newGameButton->Name = L"newGameButton";
			this->newGameButton->Size = System::Drawing::Size(127, 48);
			this->newGameButton->TabIndex = 14;
			this->newGameButton->Text = L"New Game";
			this->newGameButton->UseVisualStyleBackColor = true;
			this->newGameButton->Click += gcnew System::EventHandler(this, &MyForm::newGameButton_Click);
			// 
			// timer
			// 
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// timerLabel
			// 
			this->timerLabel->AutoSize = true;
			this->timerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->timerLabel->Location = System::Drawing::Point(67, 40);
			this->timerLabel->Name = L"timerLabel";
			this->timerLabel->Size = System::Drawing::Size(51, 25);
			this->timerLabel->TabIndex = 15;
			this->timerLabel->Text = L"0:00";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(8, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 25);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Time:";
			// 
			// enterName
			// 
			this->enterName->AutoSize = true;
			this->enterName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->enterName->Location = System::Drawing::Point(44, 458);
			this->enterName->Name = L"enterName";
			this->enterName->Size = System::Drawing::Size(161, 25);
			this->enterName->TabIndex = 18;
			this->enterName->Text = L"Enter your name:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(794, 556);
			this->Controls->Add(this->enterName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->timerLabel);
			this->Controls->Add(this->newGameButton);
			this->Controls->Add(this->clearAllButton);
			this->Controls->Add(this->scoreLabel);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->shuffleButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->guessedWordsBox);
			this->Controls->Add(this->submitButton);
			this->Controls->Add(this->guessBox);
			this->Controls->Add(this->lettersBox);
			this->Controls->Add(this->lettersLabel);
			this->Controls->Add(this->menuBar);
			this->MainMenuStrip = this->menuBar;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->Text = L"Text Twist by Ayaan Kazerouni and Joe Culberson";
			this->menuBar->ResumeLayout(false);
			this->menuBar->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
