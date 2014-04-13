#pragma once

#include "Player.h"
#include "FileIO.h"
using namespace model;


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
		HighScoresDialog(void)
		{
			InitializeComponent();
			FileIO^ file = gcnew FileIO();
			List<Player^>^ highScores = file->loadHighScores();
			for each (Player^ currPlayer in highScores)
			{
				this->addHighScore(currPlayer);
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nameColumn;
	protected: 
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  scoreColumn;

	protected: 


	protected: 


	protected: 


	protected: 

	private: System::Windows::Forms::DataGridView^  highScoreGrid;
	protected: 


	private: void addHighScore(Player^ player);

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
			this->highScoreGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->nameColumn, 
				this->scoreColumn});
			this->highScoreGrid->Location = System::Drawing::Point(12, 12);
			this->highScoreGrid->Name = L"highScoreGrid";
			this->highScoreGrid->ReadOnly = true;
			this->highScoreGrid->RowTemplate->Height = 28;
			this->highScoreGrid->Size = System::Drawing::Size(730, 465);
			this->highScoreGrid->TabIndex = 0;
			this->highScoreGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &HighScoresDialog::highScoreGrid_CellContentClick);
			// 
			// nameColumn
			// 
			this->nameColumn->HeaderText = L"Name";
			this->nameColumn->Name = L"nameColumn";
			this->nameColumn->ReadOnly = true;
			this->nameColumn->Width = 222;
			// 
			// scoreColumn
			// 
			this->scoreColumn->HeaderText = L"Score";
			this->scoreColumn->Name = L"scoreColumn";
			this->scoreColumn->ReadOnly = true;
			this->scoreColumn->Width = 222;
			// 
			// HighScoresDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 489);
			this->Controls->Add(this->highScoreGrid);
			this->Name = L"HighScoresDialog";
			this->Text = L"High Scores";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->highScoreGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void highScoreGrid_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 }
	};
}
