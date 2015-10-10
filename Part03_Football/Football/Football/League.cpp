#pragma warning( disable : 4996 )

#include "League.h"


League::League(const string& name, int numberOfTeams, int numberOfGames)
{
	setName(name);
	this->numberOfTeams = numberOfTeams;
	this->numberOfGames = numberOfGames;
}

//Start all the games in the league and remove them from the league
void League::start()
{
	try {
		for (int i = 0; i < (int)games.size(); i++)
		{
			games[i].start();
		}
		games.clear();
	}
	catch (const string msg)
	{
		cout << msg << endl;
	}
}

const League& League::operator+=(const Team& team)
{
	if ((int)teams.size() < numberOfTeams)
	{
		teams.push_back(team);
	}
	return *this;
}

const League& League::operator-=(const Team& team)
{
	vector<Team>::iterator  itr = this->teams.begin();
	vector<Team>::iterator  itrEnd = this->teams.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName().compare(team.getName()) == 0)
		{
			removeTeamByItr(itr);
			break;
		}
	}
	return *this;
}

const League& League::operator+=(const Game& game)
{
	if ((int)games.size() < numberOfGames)
	{
		games.push_back(game);
	}
	return *this;
}

void League::addTeam(const Team& team)
{
	*this += team;
}

const Team& League::getTeam(const string& name) const throw (string)
{
	vector<Team>::const_iterator itr = getTeamItr(name);
	if (itr != teams.end())
	{
		return *itr;
	}
	else 
	{
		throw "Team not found";
	}
}

void League::removeTeam(const string& name)
{
	vector<Team>::const_iterator itr = getTeamItr(name);
	removeTeamByItr(itr);
}

void League::removeTeamByItr(const vector<Team>::const_iterator& itr)
{
	if (itr != teams.end())
	{
		teams.erase(itr);
	}
}

int League::getSizeTeams() const
{
	return (int)teams.size();
}

int League::getSizeGames() const
{
	return (int)games.size();
}

vector<Team> const League::getAllTeams() const
{
	return teams;
}

vector<Game> const League::getAllGames() const
{
	return games;
}

const string& League::getName() const
{
	return name;
}

void League::setName(const string& name)
{
	this->name = name;
}

vector<Team>::const_iterator League::getTeamItr(const string& name) const
{
	vector<Team>::const_iterator  itr = teams.begin();
	vector<Team>::const_iterator  itrEnd = teams.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName().compare(name) == 0)
		{
			return itr;
		}
	}
	return itrEnd;
}