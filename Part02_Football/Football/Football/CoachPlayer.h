#ifndef _COACHPLAYER_H
#define _COACHPLAYER_H

#include "Coach.h"
#include "Player.h"

class CoachPlayer:public Coach, public Player
{
public:
	CoachPlayer(const Player& player, const Coach& coach);

	friend std::ostream& operator<<(std::ostream& os, const CoachPlayer& coachPlayer)
	{
		os << "No Implementation" << std::endl;
		return os;
	}

private:

};

#endif //_COACHPLAYER_H