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

	friend ostream& operator<<(ostream& os, const Game& game)
	{
		os << ">>>> Game" << endl;
		os << game.stadium << endl;
		os << "Team 1:" << endl << game.team1 << endl;
		os << "Team 2:" << endl << game.team2 << endl;
		for (int i = 0; i < Game::NUM_OF_REFEREES; i++)
		{
			os << "Referee " << (i+1) << ":" << endl;
			os << *game.referees[i] << endl;
		}
		return os;
	}

private:
	Stadium stadium;
	Team team1;
	Team team2;
	Referee **referees;

};

#endif // !_GAME_H
