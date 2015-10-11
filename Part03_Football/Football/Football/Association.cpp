#include "Association.h"


Association::Association(int numberOfLeagues, int numberOfReferees)
{
	this->numberOfLeagues = numberOfLeagues;
	this->numberOfReferees = numberOfReferees;
}

//Start all the leagues games (go to all the leagues and start them)
void Association::start()
{
	vector<League>::iterator  leaguesItr = leagues.begin();
	vector<League>::iterator  leaguesItrEnd = leagues.end();
	for (; leaguesItr != leaguesItrEnd; ++leaguesItr)
	{
		(*leaguesItr).start();
	}
}

void Association::addLeague(const League& league)
{
	if (getSizeLeagues() < numberOfLeagues)
	{
		leagues.push_back(league);
	}
}

const League& Association::getLeague(const char* name) const throw (string)
{
	vector<League>::const_iterator itr = getLeagueItr(name);
	if (itr != leagues.end())
	{
		return *itr;
	}
	else
	{
		throw "League not found";
	}
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

const Referee& Association::getReferee(const char* name) const throw(string)
{
	vector<Referee>::const_iterator itr = getRefereeItr(name);
	if (itr != referees.end())
	{
		return *itr;
	}
	else
	{
		throw "Referee Not Found";
	}
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

ostream& operator<<(ostream& os, const Association& association)
{
	os << ">>>>>>>>>>>>>>>> Association" << endl;
	os << endl << ">>>>>>>> Number of Leagues: " << association.getSizeLeagues() << "/" << association.numberOfLeagues << endl;
	vector<League>::const_iterator  leaguesItr = association.leagues.begin();
	vector<League>::const_iterator  leaguesItrEnd = association.leagues.end();
	for (; leaguesItr != leaguesItrEnd; ++leaguesItr)
	{
		os << *leaguesItr << endl;
	}

	os << endl << ">>>>>>>> Number of Referees: " << association.getSizeReferees() << "/" << association.numberOfReferees << endl;
	vector<Referee>::const_iterator  refereesItr = association.referees.begin();
	vector<Referee>::const_iterator  refereesItrEnd = association.referees.end();
	for (; refereesItr != refereesItrEnd; ++refereesItr)
	{
		os << *refereesItr << endl;
	}

	return os;
}
