#ifndef _COACHPLAYER_H
#define _COACHPLAYER_H

#include "Coach.h"
#include "Player.h"

class CoachPlayer: public Player, public Coach
{
public:
	CoachPlayer(const Player& player, const Coach& coach);

	virtual StaffMember* clone() const;

	virtual void toOs(ostream& os) const;

private:

};

#endif //_COACHPLAYER_H