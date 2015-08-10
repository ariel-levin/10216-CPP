#ifndef __LEAGUE_H
#define __LEAGUE_H

#include <iostream>
#include <ctime>
#include "team.h"
#include "game.h"

using namespace std;


class League
{
public:
	League(const char* name, const tm& startDate, const tm& endDate);
	League(const League& other);
	~League();

	const League& operator=(const League& other);

	void setName(const char* name);
	void setStartDate(const tm& startDate);
	void setEndDate(const tm& endDate);

	const char* getName() const			{ return name; };
	const tm& getStartDate() const		{ return startDate; };
	const tm& getEndDate() const		{ return endDate; };
	const Team*const* getTeams() const	{ return teams; };
	int getNumOfTeams() const			{ return numOfTeams; };
	const Game*const* getGames() const	{ return games; };
	int getNumOfGames() const			{ return numOfGames; };

	void addTeam(const Team& team);			// increment numOfTeams
	void addGame(const Game& game);			// increment numOfGames
	void removeTeam(const Team& team);		// reduce numOfTeams
	void removeGame(const Game& game);		// reduce numOfGames

	friend ostream& operator<<(ostream& os, const League& l);

private:
	char* name;
	tm startDate;
	tm endDate;
	Team** teams;
	int numOfTeams;
	Game** games;
	int numOfGames;

};

#endif	// __LEAGUE_H