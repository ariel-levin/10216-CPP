#ifndef __TEAM_H
#define __TEAM_H

#include <iostream>
#include "coach.h"
#include "player.h"
#include "sponsor.h"

using namespace std;


class Team
{
public:
	Team(const Coach& coach); 
	Team(const Team& other);
	~Team();

	const Team& operator=(const Team& other);
	const Team& operator+=(const Player& player);	// will use addPlayer()
	const Team& operator-=(const Player& player);	// will use removePlayer()
	bool operator==(const Sponsor& sponsor);
	friend bool operator==(const Sponsor& sponsor, const Team& team);

	void setCoach(const Coach& coach);

	const Coach* getCoach() const				{ return coach; }
	const Player*const* getPlayers() const		{ return players; }
	int getNumOfPlayers() const					{ return numOfPlayers; }
	const Sponsor*const* getSponsors() const	{ return sponsors; }
	int getNumOfSponsors() const				{ return numOfSponsors; }

	void addPlayer(const Player& player);			// increment numOfPlayers
	void addSponsor(const Sponsor& sponsor);		// increment numOfSponsors
	void removePlayer(const Player& player);		// reduce numOfPlayers
	void removeSponsor(const Sponsor& sponsor);		// reduce numOfSponsors

	friend ostream& operator<<(ostream& os, const Team& t);


private:
	Coach* coach;
	Player** players;
	int numOfPlayers;
	Sponsor** sponsors;
	int numOfSponsors;

};

#endif	// __TEAM_H