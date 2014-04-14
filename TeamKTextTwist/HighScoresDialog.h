#pragma once

#include "Player.h"
#include "FileIO.h"
#include "HighScore.h"
using namespace model;

using namespace System::Collections::Generic;

namespace controller {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HighScoresDialog
	/// </summary>
	public ref class HighScoresDialog : public System::Windows::Forms::Form
	{
	public:
		HighScoresDialog(List<HighScore^>^ highScores)
		{
			InitializeComponent();
			if (highScores->Count == 0) {
				MessageBox::Show("There are no high scores to display.");
			} else {
				for each (HighScore^ currPlayer in highScores)
				{
					this->addHighScore(currPlayer);
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HighScoresDialog()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::Button^  resetBtn;
	private: System::Windows::Forms::Button^  closeBtn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  scoreColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  timeAllotted;
	private: System::Windows::Forms::Label^  label1;




	private: System::Windows::Forms::DataGridView^  highScoreGrid;
	private: System::Void resetBtn_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void closeBtn_Click(System::Object^  sender, System::EventArgs^  e);
	private: void addHighScore(HighScore^ highScore);
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
			this->highScoreGrid = (gcnew System::Windows::Forms::DataGridView());
			this->nameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->scoreColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->timeAllotted = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->resetBtn = (gcnew System::Windows::Forms::Button());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->highScoreGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// highScoreGrid
			// 
			this->highScoreGrid->AllowUserToAddRows = false;
			this->highScoreGrid->AllowUserToDeleteRows = false;
			this->highScoreGrid->AllowUserToResizeColumns = false;
			this->highScoreGrid->AllowUserToResizeRows = false;
			this->highScoreGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->highScoreGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->nameColumn, 
				this->scoreColumn, this->timeAllotted});
			this->highScoreGrid->Location = System::Drawing::Point(12, 56);
			this->highScoreGrid->Name = L"highScoreGrid";
			this->highScoreGrid->ReadOnly = true;
			this->highScoreGrid->RowHeadersVisible = false;
			this->highScoreGrid->RowTemplate->Height = 28;
			this->highScoreGrid->Size = System::Drawing::Size(724, 469);
			this->highScoreGrid->TabIndex = 0;
			// 
			// nameColumn
			// 
			this->nameColumn->HeaderText = L"Name";
			this->nameColumn->Name = L"nameColumn";
			this->nameColumn->ReadOnly = true;
			this->nameColumn->Width = 160;
			// 
			// scoreColumn
			// 
			this->scoreColumn->HeaderText = L"Score";
			this->scoreColumn->Name = L"scoreColumn";
			this->scoreColumn->ReadOnly = true;
			this->scoreColumn->Width = 160;
			// 
			// timeAllotted
			// 
			this->timeAllotted->HeaderText = L"Time Allotted (minutes)";
			this->timeAllotted->Name = L"timeAllotted";
			this->timeAllotted->ReadOnly = true;
			this->timeAllotted->Width = 160;
			// 
			// resetBtn
			// 
			this->resetBtn->Location = System::Drawing::Point(145, 539);
			this->resetBtn->Name = L"resetBtn";
			this->resetBtn->Size = System::Drawing::Size(171, 33);
			this->resetBtn->TabIndex = 1;
			this->resetBtn->Text = L"Reset High Scores";
			this->resetBtn->UseVisualStyleBackColor = true;
			this->resetBtn->Click += gcnew System::EventHandler(this, &HighScoresDialog::resetBtn_Click);
			// 
			// closeBtn
			// 
			this->closeBtn->Location = System::Drawing::Point(441, 539);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(171, 33);
			this->closeBtn->TabIndex = 2;
			this->closeBtn->Text = L"Close";
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &HighScoresDialog::closeBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(237, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(264, 32);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Top 10 High Scores";
			// 
			// HighScoresDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 583);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->closeBtn);
			this->Controls->Add(this->resetBtn);
			this->Controls->Add(this->highScoreGrid);
			this->Name = L"HighScoresDialog";
			this->Text = L"High Scores";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->highScoreGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
