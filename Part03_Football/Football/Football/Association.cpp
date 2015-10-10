#include "Association.h"


Association::Association(int numberOfLeagues, int numberOfReferees)
{
	this->numberOfLeagues = numberOfLeagues;
	this->numberOfReferees = numberOfReferees;
}

//Start all the leagues games (go to all the leagues and start them)
void Association::start()
{
	for (int i = 0; i < getSizeLeagues(); i++)
	{
		leagues[i].start();
	}
}

void Association::addLeague(const League& league)
{
	if (getSizeLeagues() < numberOfLeagues)
	{
		leagues.push_back(league);
	}
}

const League& Association::getLeague(const char* name) const
{
	return *getLeagueItr(name);
}

void Association::removeLeague(const char* name)
{
	vector<League>::const_iterator itr = getLeagueItr(name);

	if (itr != leagues.end())
	{
		leagues.erase(itr);
	}
}

void Association::addReferee(const Referee& referee)
{
	if (getSizeReferees() < numberOfReferees)
	{
		referees.push_back(referee);
	}
}

const Referee& Association::getReferee(const char* name) const
{
	return *getRefereeItr(name);
}

void Association::removeReferee(const char* name)
{
	vector<Referee>::const_iterator itr = getRefereeItr(name);

	if (itr != referees.end())
	{
		referees.erase(itr);
	}
}

int Association::getSizeLeagues() const
{
	return (int)leagues.size();
}

int Association::getSizeReferees() const
{
	return (int)referees.size();
}

vector<League>::const_iterator Association::getLeagueItr(const char* name) const
{
	vector<League>::const_iterator  itr = leagues.begin();
	vector<League>::const_iterator  itrEnd = leagues.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName().compare(name) == 0)
		{
			return itr;
		}
	}
	return itrEnd;
}

vector<Referee>::const_iterator Association::getRefereeItr(const char* name) const
{
	vector<Referee>::const_iterator  itr = referees.begin();
	vector<Referee>::const_iterator  itrEnd = referees.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr).getName().compare(name) == 0)
		{
			return itr;
		}
	}
	return itrEnd;
}