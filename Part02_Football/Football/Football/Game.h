#ifndef _GAME_H
#define _GAME_H

#include <iostream>
using namespace std;

#include "Stadium.h"
#include "Team.h"
#include "Referee.h"

class Game
{
	static const int NUM_OF_REFEREES = 4;

public:
	Game(const Stadium& stadium, Team& team1 , const Team& team2 , Referee *referees[NUM_OF_REFEREES]);

	void start() const;

	friend ostream& operator<<(ostream& os, const Game& game);

private:
	Stadium stadium;
	Team team1;
	Team team2;
	Referee **referees;

};

#endif // !_GAME_H
