#ifndef _LEAGUE_H
#define _LEAGUE_H

#include <iostream>
using namespace std;

#include "Team.h"
#include "Game.h"

class League
{
public:
	League(char* name, int numberOfTeams, int numberOfGames);
	League(const League& other);
	~League();
	League& operator=(const League& other);

	void start() const; //Start all the games in the league and remove them from the league

	const League& operator+=(const Team& team);//Add team to the league
	const League& operator-=(const Team& team);//Remove team to the league

	const League& operator+=(const Game& game);//Add game to the league

	void addTeam(const Team& team);//Use operator +=
	const Team& getTeam(const char* name) const;
	void removeTeam(const char* name);

	const Team* const getAllTeams() const;
	const Game* const getAllGames() const;

	const char* getName() const;
	void setName(const char* name);

	friend ostream& operator<<(ostream& os, const League& league)
	{
		os << "No Implementation" << std::endl;
		return os;
	}

private:
	int numberOfTeams;
	Team* teams;
	int numberOfGames;
	Game* games;
	char* name;

};

#endif // !_LEAGUE_H
