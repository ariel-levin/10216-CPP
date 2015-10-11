#ifndef _LEAGUE_H
#define _LEAGUE_H

#include <iostream>
using namespace std;

#include "Team.h"
#include "Game.h"

class League
{
public:
	League(const char* name, int numberOfTeams, int numberOfGames);
	League(const League& other);
	~League();
	League& operator=(const League& other);

	void start();

	const League& operator+=(const Team& team);//Add team to the league
	const League& operator-=(const Team& team);//Remove team to the league

	const League& operator+=(const Game& game);//Add game to the league

	void addTeam(const Team& team);
	const Team& getTeam(const char* name) const;
	void removeTeam(const char* name);
	void removeTeamByIndex(int index);

	Team*const* const getAllTeams() const;		// #note# read before presentation
	Game*const* const getAllGames() const;

	const char* getName() const;
	void setName(const char* name);

	friend ostream& operator<<(ostream& os, const League& league);

private:
	int numberOfTeams;
	int sizeTeams;
	Team** teams;
	int numberOfGames;
	int sizeGames;
	Game** games;
	char* name;

	void setTeams(Team** teams, int size, int numberOfTeams);
	void setGames(Game** games, int size, int numberOfGames);
	int getTeamIndex(const char* name) const;

};

#endif // !_LEAGUE_H
