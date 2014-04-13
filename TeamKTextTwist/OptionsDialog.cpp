#include "OptionsDialog.h"

namespace controller {

int OptionsDialog::getTimeLimit() {
	if(this->minuteOneButton->Checked) {
		return ONE_MINUTE;
	} else if (this->minuteTwoButton->Checked) {
		return TWO_MINUTES;
	} else {
		return THREE_MINUTES;
	}
}

bool OptionsDialog::getLetterReuse() {
	return this->letterReuse->Checked;
}

}