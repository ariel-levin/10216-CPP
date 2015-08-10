#ifndef __PLAYER_H
#define __PLAYER_H

#include <iostream>
#include "employee.h"

using namespace std;


class Player : public Employee
{
public:
	const static enum POSITION { GK, CB, LB, RB, LWB, RWB, SW, DM, CM, AM, LW, RW, CF, WF };

	Player(const Employee& emp, POSITION pos, int rank);

	void setPosition(POSITION pos);
	void setRank(int rank);

	POSITION getPosition() const { return pos; };
	int getRank() const { return rank; };

	friend ostream& operator<<(ostream& os, const Player& p);

private:
	POSITION pos;
	int rank;

};

#endif	// __PLAYER_H




/* reference for POSITION types
*	http://www.football-bible.com/soccer-info/soccer-positions-explained.html
*
* * */

/*

const char* getPositionName() const { return posName[pos]; };

const char* posName[14] = { "Goalkeeper", "Center-back", "Left Full-back",
							"Right Full-back", "Left Wing-back", "Right Wing-back",
							"Sweeper", "Defending midfielder", "Central midfielder",
							"Attacking midfielder", "Left Wide midfielders",
							"Right Wide midfielders", "Center-forward",
							"Withdrawn striker forward" };

*/