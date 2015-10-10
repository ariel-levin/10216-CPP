#ifndef _LEAGUE_H
#define _LEAGUE_H

#include <string>
#include <iostream>
using namespace std;

#include "Team.h"
#include "Game.h"


class League
{
public:
	League(const string& name, int numberOfTeams, int numberOfGames);
	League(const League& other);
	~League();
	League& operator=(const League& other);

	void start();

	const League& operator+=(const Team& team);//Add team to the league
	const League& operator-=(const Team& team);//Remove team to the league

	const League& operator+=(const Game& game);//Add game to the league

	void addTeam(const Team& team);
	const Team& getTeam(const string& name) const;
	void removeTeam(const string& name);
	void removeTeamByIndex(int index);

	Team*const* const getAllTeams() const;		// #note# read before presentation
	Game*const* const getAllGames() const;

	const string& getName() const;
	void setName(const string& name);

	friend ostream& operator<<(ostream& os, const League& league)
	{
		os << ">>>>>>>> League name: " << league.name << endl;
		os << endl << ">>>> Number of Teams: " << league.sizeTeams << "/" << league.numberOfTeams << endl;
		for (int i = 0; i < league.sizeTeams; i++)
		{
			os << *league.teams[i] << endl;
		}
		os << endl << ">>>> Number of Games : " << league.sizeGames << "/" << league.numberOfGames << endl;
		for (int i = 0; i < league.sizeGames; i++)
		{
			os << *league.games[i] << endl;
		}
		return os;
	}

private:
	int numberOfTeams;
	int sizeTeams;
	Team** teams;
	int numberOfGames;
	int sizeGames;
	Game** games;
	string name;

	void setTeams(Team** teams, int size, int numberOfTeams);
	void setGames(Game** games, int size, int numberOfGames);
	int getTeamIndex(const string& name) const;

};

#endif // !_LEAGUE_H
