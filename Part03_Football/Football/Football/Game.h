#ifndef _GAME_H
#define _GAME_H

#include <iostream>
using namespace std;

#include "Stadium.h"
#include "Team.h"
#include "Referee.h"
#include "LinkedList.h"

class Game
{
public:
	Game(const Stadium& stadium, Team& team1, const Team& team2, const LinkedList<Referee>& referees);

	void start() const;

	friend ostream& operator<<(ostream& os, const Game& game);

private:
	Stadium stadium;
	Team team1;
	Team team2;
	LinkedList<Referee> referees;

};

#endif // !_GAME_H
