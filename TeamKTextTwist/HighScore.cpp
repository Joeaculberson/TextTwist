#include "HighScore.h"

namespace model {

/// <summary>
/// The overload operator < for the player. Compares by score.
/// </summary>
/// <pre>player != nullptr</pre>
/// <post>player == this->getPlayer()</post>
/// <post>timeAlloted == this->getTimeAllotted()</post>
/// <param value="player">The player with the high score.</param>
HighScore::HighScore(Player^ player, int timeAllotted)
{
	if (player == nullptr) {
		throw gcnew ArgumentException("player cannot be null.");
	}
	this->player = player;
	this->timeAllotted = timeAllotted;
}

/// <summary>
/// Returns the player.
/// </summary>
/// <pre>None.</pre>
/// <return>The player.</return>
Player^ HighScore::getPlayer() {
	return this->player;
}

/// <summary>
/// Returns the time allotted.
/// </summary>
/// <pre>None.</pre>
/// <return>The time alloted.</return>
int HighScore::getTimeAllotted() {
	return this->timeAllotted;
}

}