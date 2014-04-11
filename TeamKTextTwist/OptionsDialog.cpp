#include "OptionsDialog.h"

namespace TeamKTextTwist {

int OptionsDialog::getTimeLimit() {
	if(this->minuteOneButton->Checked) {
		return 1;
	} else if (this->minuteTwoButton->Checked) {
		return 2;
	} else if (this->minuteThreeButton->Checked) {
		return 3;
	}
}

bool OptionsDialog::getLetterReuse() {
	return this->letterReuse->Checked;
}

}