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

	friend ostream& operator<<(ostream& os, const Game& game)
	{
		os << ">>>> Game" << endl;
		os << game.stadium << endl;
		os << "Team 1:" << endl << game.team1 << endl;
		os << "Team 2:" << endl << game.team2 << endl;
		os << "Referees:" << endl;
		os << game.referees << endl;
		return os;
	}

private:
	Stadium stadium;
	Team team1;
	Team team2;
	LinkedList<Referee> referees;

};

#endif // !_GAME_H
