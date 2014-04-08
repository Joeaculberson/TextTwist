#include "Game.h"

#include "FileIO.h"
using namespace model;

#include <map>
#include <vector>
using namespace std;

namespace controller {

   /**
	* Creates a Game object with assigned values.
	*
	* @pre none
	*/
	Game::Game()
	{

	}

   /**
    * Runs the program.
	*
	* @pre none
	*/
	void Game::run() {
		FileIO ^file = gcnew FileIO();
		vector<string> words = file->parseFile();	
	}

}

