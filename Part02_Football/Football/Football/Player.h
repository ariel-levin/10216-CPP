#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
using namespace std;

#include "StaffMember.h"

class Player: virtual public StaffMember
{
public:
	enum Position
	{
		GOALKEEPER,
		DEFENDER,
		MIDFIELDER,
		STRICKER
	};

	Player(const StaffMember& staffMember, Position position, int number);

	Position getPosition() const;
	void setPosition(Position position);

	int getNumber() const;
	void setNumber(int number);

	friend ostream& operator<<(ostream& os, const Player& league)
	{
		os << "No Implementation" << std::endl;
		return os;
	}

private:
	Position position;
	int number;

};

#endif // !_PLAYER_H
