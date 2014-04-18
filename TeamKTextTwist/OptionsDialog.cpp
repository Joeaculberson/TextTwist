#include "OptionsDialog.h"

namespace controller {

///<summary>
/// Creates an options dialog with assigned values.
///</summary>
///<pre>timeLimit == 1 || timeLimit == 2 || timeLimit == 3</pre>
///<param value="timeLimit">The time limit that will display</param>
///<param value="letterReuse">If letter reuse should be checked or not</param>
OptionsDialog::OptionsDialog(int timeLimit, bool letterReuse) {
	InitializeComponent();

	this->minuteOneButton->Checked = false;
	this->minuteTwoButton->Checked = false;
	this->minuteThreeButton->Checked = false;

	if(timeLimit == ONE_MINUTE) {
		this->minuteOneButton->Checked = true;
	} else if(timeLimit == TWO_MINUTES) {
		this->minuteTwoButton->Checked = true;
	} else if(timeLimit == THREE_MINUTES) {
		this->minuteThreeButton->Checked = true;
	} else {
		throw gcnew ArgumentException("Invalid time limit.");
	}

	if(letterReuse) {
		this->letterReuse->Checked = true;
	} else {
		this->letterReuse->Checked = false;
	}
}


///<summary>
/// Returns the time limit.
///</summary>
///<pre>None.</pre>
///<return>The time limit.</return>
int OptionsDialog::getTimeLimit() {
	if(this->minuteOneButton->Checked) {
		return ONE_MINUTE;
	} else if (this->minuteTwoButton->Checked) {
		return TWO_MINUTES;
	} else {
		return THREE_MINUTES;
	}
}

///<summary>
/// Returns true if the letter reuse is on.
///</summary>
///<pre>None.</pre>
///<return>True if the letter reuse is on.</return>
bool OptionsDialog::getLetterReuse() {
	return this->letterReuse->Checked;
}

}