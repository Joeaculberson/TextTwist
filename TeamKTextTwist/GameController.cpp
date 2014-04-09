#include "GameController.h"
#include "FileIO.h"

namespace model {
GameController::GameController(void)
{

}

int GameController::wordIsContained(vector<string> wordList, const string& word, int first, int last) {
	if (last < first) {
		return -1;
	}

	int mid = this->getMidpoint(first, last);
	if (wordList[mid] > word) {
		return this->wordIsContained(wordList, word, first, mid - 1);
	} else if (wordList[mid] < word) {
		return this->wordIsContained(wordList, word, mid + 1, last);
	} else {
		return mid;
	}
}

int GameController::getMidpoint(int first, int last) {
	return (first + last) / 2;
}

bool GameController::contains(vector<string> wordList, const string& word) {
	return this->wordIsContained(wordList, word, 0, wordList.size()-1) == -1;
}
}
