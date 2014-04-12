#include "HighScoresDialog.h"

using namespace System::Collections::Generic;
using namespace System;

namespace controller {

void HighScoresDialog::addHighScore(Player^ player)
{
	DataGridViewRow^ row = (DataGridViewRow^) this->highScoreGrid->Rows[0]->Clone();
    if (row != nullptr)
    {
		row->Cells[0]->Value = player->getName();
        row->Cells[1]->Value = player->getScore();
        this->highScoreGrid->Rows->Add(row);
    }
}

}