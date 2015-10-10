#pragma warning( disable : 4996 )

#include "League.h"


League::League(char* name, int numberOfTeams, int numberOfGames) : name(NULL)
{
	setName(name);
	this->numberOfTeams = numberOfTeams;
	this->numberOfGames = numberOfGames;
	this->sizeTeams = 0;
	this->sizeGames = 0;
	this->teams = new Team*[numberOfTeams];
	this->games = new Game*[numberOfGames];
}

League::League(const League& other) : name(NULL), teams(NULL), games(NULL)
{
	*this = other;
}

League::~League()
{
	delete[] name;
	for (int i = 0; i < sizeTeams; i++)
	{
		delete teams[i];
	}
	delete[] teams;
	for (int i = 0; i < sizeGames; i++)
	{
		delete games[i];
	}
	delete[] games;
}

League& League::operator=(const League& other)
{
	if (this != &other)
	{
		setName(other.name);
		numberOfTeams = other.numberOfTeams;
		numberOfGames = other.numberOfGames;
		sizeTeams = other.sizeTeams;
		sizeGames = other.sizeGames;
		setTeams(other.teams, other.sizeTeams, other.numberOfTeams);
		setGames(other.games, other.sizeGames, other.numberOfGames);
	}
	return *this;
}

//Start all the games in the league and remove them from the league
void League::start()
{
	for (int i = 0; i < sizeGames; i++)
	{
		games[i]->start();
	}
	for (int i = 0; i < sizeGames; i++)
	{
		delete games[i];
	}
	sizeGames = 0;
}

const League& League::operator+=(const Team& team)
{
	if (sizeTeams < numberOfTeams)
	{
		teams[sizeTeams] = new Team(team);
		++sizeTeams;
	}
	return *this;
}

const League& League::operator-=(const Team& team)
{
	for (int i = 0; i < numberOfTeams; i++)
	{
		if (strcmp((*teams[i]).getName(), team.getName()) == 0)
		{
			removeTeamByIndex(i);
			break;
		}
	}
	return *this;
}

const League& League::operator+=(const Game& game)
{
	if (sizeGames < numberOfGames)
	{
		games[sizeGames] = new Game(game);
		++sizeGames;
	}
	return *this;
}

void League::addTeam(const Team& team)
{
	*this += team;
}

const Team& League::getTeam(const char* name) const
{
	return *teams[getTeamIndex(name)];
}

void League::removeTeam(const char* name)
{
	int index = getTeamIndex(name);
	removeTeamByIndex(index);
}

void League::removeTeamByIndex(int index)
{
	if (index >= 0 && index < sizeTeams)
	{
		delete teams[index];
		for (int i = index; i < sizeTeams - 1; i++)
		{
			teams[i] = teams[i + 1];
		}
		--sizeTeams;
	}
}

Team*const* const League::getAllTeams() const
{
	return teams;
}

Game*const* const League::getAllGames() const
{
	return games;
}

const char* League::getName() const
{
	return name;
}

void League::setName(const char* name)
{
	if (this->name != name)
	{
		delete[] this->name;
		this->name = strdup(name);
	}
}

void League::setTeams(Team** teams, int size, int numberOfTeams)
{
	delete[] this->teams;
	if (size == 0)
	{
		this->teams = NULL;
	}
	else
	{
		this->teams = new Team*[numberOfTeams];
		for (int i = 0; i < size; i++)
		{
			this->teams[i] = new Team(*teams[i]);
		}
	}
}

void League::setGames(Game** games, int size, int numberOfGames)
{
	delete[] this->games;
	if (size == 0)
	{
		this->games = NULL;
	}
	else
	{
		this->games = new Game*[numberOfGames];
		for (int i = 0; i < size; i++)
		{
			this->games[i] = new Game(*games[i]);
		}
	}
}

int League::getTeamIndex(const char* name) const
{
	for (int i = 0; i < sizeTeams; i++)
	{
		if (strcmp((*teams[i]).getName(), name) == 0)
		{
			return i;
		}
	}
	return -1;
}