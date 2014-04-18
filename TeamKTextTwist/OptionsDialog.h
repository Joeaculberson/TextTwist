#pragma once

namespace controller {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OptionsDialog
	/// </summary>
	public ref class OptionsDialog : public System::Windows::Forms::Form
	{
	public: int getTimeLimit();
	public: bool getLetterReuse();
	public:
		OptionsDialog(int timeLimit, bool letterReuse);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OptionsDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBoxTimer;
	protected: 

	protected: 
	private: System::Windows::Forms::RadioButton^  minuteThreeButton;
	private: System::Windows::Forms::RadioButton^  minuteTwoButton;
	private: System::Windows::Forms::RadioButton^  minuteOneButton;
	private: System::Windows::Forms::Button^  submitTimer;
	private: System::Windows::Forms::Button^  cancelTimer;
	private: System::Windows::Forms::CheckBox^  letterReuse;

	private: static const int ONE_MINUTE = 1;
	private: static const int TWO_MINUTES = 2;
	private: static const int THREE_MINUTES = 3;


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
			this->groupBoxTimer = (gcnew System::Windows::Forms::GroupBox());
			this->minuteThreeButton = (gcnew System::Windows::Forms::RadioButton());
			this->minuteTwoButton = (gcnew System::Windows::Forms::RadioButton());
			this->minuteOneButton = (gcnew System::Windows::Forms::RadioButton());
			this->submitTimer = (gcnew System::Windows::Forms::Button());
			this->cancelTimer = (gcnew System::Windows::Forms::Button());
			this->letterReuse = (gcnew System::Windows::Forms::CheckBox());
			this->groupBoxTimer->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBoxTimer
			// 
			this->groupBoxTimer->Controls->Add(this->minuteThreeButton);
			this->groupBoxTimer->Controls->Add(this->minuteTwoButton);
			this->groupBoxTimer->Controls->Add(this->minuteOneButton);
			this->groupBoxTimer->Location = System::Drawing::Point(17, 19);
			this->groupBoxTimer->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBoxTimer->Name = L"groupBoxTimer";
			this->groupBoxTimer->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBoxTimer->Size = System::Drawing::Size(117, 94);
			this->groupBoxTimer->TabIndex = 0;
			this->groupBoxTimer->TabStop = false;
			this->groupBoxTimer->Text = L"Timer";
			// 
			// minuteThreeButton
			// 
			this->minuteThreeButton->AutoSize = true;
			this->minuteThreeButton->Location = System::Drawing::Point(17, 62);
			this->minuteThreeButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->minuteThreeButton->Name = L"minuteThreeButton";
			this->minuteThreeButton->Size = System::Drawing::Size(70, 17);
			this->minuteThreeButton->TabIndex = 1;
			this->minuteThreeButton->Text = L"3 minutes";
			this->minuteThreeButton->UseVisualStyleBackColor = true;
			// 
			// minuteTwoButton
			// 
			this->minuteTwoButton->AutoSize = true;
			this->minuteTwoButton->Location = System::Drawing::Point(17, 43);
			this->minuteTwoButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->minuteTwoButton->Name = L"minuteTwoButton";
			this->minuteTwoButton->Size = System::Drawing::Size(70, 17);
			this->minuteTwoButton->TabIndex = 1;
			this->minuteTwoButton->Text = L"2 minutes";
			this->minuteTwoButton->UseVisualStyleBackColor = true;
			// 
			// minuteOneButton
			// 
			this->minuteOneButton->AutoSize = true;
			this->minuteOneButton->Location = System::Drawing::Point(17, 23);
			this->minuteOneButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->minuteOneButton->Name = L"minuteOneButton";
			this->minuteOneButton->Size = System::Drawing::Size(65, 17);
			this->minuteOneButton->TabIndex = 0;
			this->minuteOneButton->Text = L"1 minute";
			this->minuteOneButton->UseVisualStyleBackColor = true;
			// 
			// submitTimer
			// 
			this->submitTimer->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->submitTimer->Location = System::Drawing::Point(159, 133);
			this->submitTimer->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->submitTimer->Name = L"submitTimer";
			this->submitTimer->Size = System::Drawing::Size(86, 24);
			this->submitTimer->TabIndex = 1;
			this->submitTimer->Text = L"Submit";
			this->submitTimer->UseVisualStyleBackColor = true;
			// 
			// cancelTimer
			// 
			this->cancelTimer->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelTimer->Location = System::Drawing::Point(29, 133);
			this->cancelTimer->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->cancelTimer->Name = L"cancelTimer";
			this->cancelTimer->Size = System::Drawing::Size(86, 24);
			this->cancelTimer->TabIndex = 2;
			this->cancelTimer->Text = L"Cancel";
			this->cancelTimer->UseVisualStyleBackColor = true;
			// 
			// letterReuse
			// 
			this->letterReuse->AutoSize = true;
			this->letterReuse->Location = System::Drawing::Point(159, 62);
			this->letterReuse->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->letterReuse->Name = L"letterReuse";
			this->letterReuse->Size = System::Drawing::Size(87, 17);
			this->letterReuse->TabIndex = 3;
			this->letterReuse->Text = L"Letter Reuse";
			this->letterReuse->UseVisualStyleBackColor = true;
			// 
			// OptionsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(273, 175);
			this->Controls->Add(this->letterReuse);
			this->Controls->Add(this->cancelTimer);
			this->Controls->Add(this->submitTimer);
			this->Controls->Add(this->groupBoxTimer);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"OptionsDialog";
			this->Text = L"Options";
			this->groupBoxTimer->ResumeLayout(false);
			this->groupBoxTimer->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
