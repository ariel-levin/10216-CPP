#ifndef _LEAGUE_H
#define _LEAGUE_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "Team.h"
#include "Game.h"


class League
{
public:
	League(const string& name, int numberOfTeams, int numberOfGames);

	void start();

	const League& operator+=(const Team& team);//Add team to the league
	const League& operator-=(const Team& team);//Remove team to the league

	const League& operator+=(const Game& game);//Add game to the league

	void addTeam(const Team& team);
	const Team& getTeam(const string& name) const;
	void removeTeam(const string& name);
	void removeTeamByItr(const vector<Team>::const_iterator& itr);

	int getSizeTeams() const;
	int getSizeGames() const;
	vector<Team> const getAllTeams() const;
	vector<Game> const getAllGames() const;

	const string& getName() const;
	void setName(const string& name);

	friend ostream& operator<<(ostream& os, const League& league)
	{
		os << ">>>>>>>> League name: " << league.name << endl;
		os << endl << ">>>> Number of Teams: " << league.getSizeTeams() << "/" << league.numberOfTeams << endl;
		for (int i = 0; i < league.getSizeTeams(); i++)
		{
			os << league.teams[i] << endl;
		}
		os << endl << ">>>> Number of Games : " << league.getSizeGames() << "/" << league.numberOfGames << endl;
		for (int i = 0; i < league.getSizeGames(); i++)
		{
			os << league.games[i] << endl;
		}
		return os;
	}

private:
	int numberOfTeams;
	vector<Team> teams;
	int numberOfGames;
	vector<Game> games;
	string name;

	vector<Team>::const_iterator getTeamItr(const string& name) const;
};

#endif // !_LEAGUE_H
