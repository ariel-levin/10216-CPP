#include "Association.h"


Association::Association(int numberOfLeagues, int numberOfReferees)
{
	this->numberOfLeagues = numberOfLeagues;
	this->numberOfReferees = numberOfReferees;
	this->sizeLeagues = 0;
	this->sizeReferees = 0;
	this->leagues = new League*[numberOfLeagues];
	this->referees = new Referee*[numberOfReferees];
}

Association::~Association()
{
	for (int i = 0; i < sizeLeagues; i++)
	{
		delete leagues[i];
	}
	delete[] leagues;
	for (int i = 0; i < sizeReferees; i++)
	{
		delete referees[i];
	}
	delete[] referees;
}

//Start all the leagues games (go to all the leagues and start them)
void Association::start() const
{
	for (int i = 0; i < sizeLeagues; i++)
	{
		leagues[i]->start();
	}
}

void Association::addLeague(const League& league)
{
	if (sizeLeagues < numberOfLeagues)
	{
		leagues[sizeLeagues] = new League(league);
		++sizeLeagues;
	}
}

const League& Association::getLeague(const char* name) const
{
	return *leagues[getLeagueIndex(name)];
}

void Association::removeLeague(const char* name)
{
	int index = getLeagueIndex(name);
	if (index >= 0 && index < sizeLeagues)
	{
		delete leagues[index];
		for (int i = index; i < sizeLeagues - 1; i++)
		{
			leagues[i] = leagues[i + 1];
		}
		--sizeLeagues;
	}
}

void Association::addReferee(const Referee& referee)
{
	if (sizeReferees < numberOfReferees)
	{
		referees[sizeReferees] = new Referee(referee);
		++sizeReferees;
	}
}

const Referee& Association::getReferee(const char* name) const
{
	return *referees[getRefereeIndex(name)];
}

void Association::removeReferee(const char* name)
{
	int index = getRefereeIndex(name);
	if (index >= 0 && index < sizeReferees)
	{
		delete referees[index];
		for (int i = index; i < sizeReferees - 1; i++)
		{
			referees[i] = referees[i + 1];
		}
		--sizeReferees;
	}
}

int Association::getLeagueIndex(const char* name) const
{
	for (int i = 0; i < sizeLeagues; i++)
	{
		if (strcmp((*leagues[i]).getName(), name) == 0)
		{
			return i;
		}
	}
	return -1;
}

int Association::getRefereeIndex(const char* name) const
{
	for (int i = 0; i < sizeReferees; i++)
	{
		if (strcmp((*referees[i]).getName(), name) == 0)
		{
			return i;
		}
	}
	return -1;
}

ostream& operator<<(ostream& os, const Association& association)
{
	os << ">>>>>>>>>>>>>>>> Association" << endl;
	os << endl << ">>>>>>>> Number of Leagues: " << association.sizeLeagues << "/" << association.numberOfLeagues << endl;
	for (int i = 0; i < association.sizeLeagues; i++)
	{
		os << *association.leagues[i] << endl;
	}
	os << endl << ">>>>>>>> Number of Referees: " << association.sizeReferees << "/" << association.numberOfReferees << endl;
	for (int i = 0; i < association.sizeReferees; i++)
	{
		os << *association.referees[i] << endl;
	}
	return os;
}
