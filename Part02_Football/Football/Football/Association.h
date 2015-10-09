#ifndef _ASSOCIATION_H
#define _ASSOCIATION_H

#include <iostream>
using namespace std;

#include "League.h"
#include "Referee.h"


class Association
{
public:
	Association(int numberOfLeagues, int numberOfReferees);
	~Association();

	void start() const;

	void addLeague(const League& league);
	const League& getLeague(const char* name) const;
	void removeLeague(const char* name);

	void addReferee(const Referee& referee);
	const Referee& getReferee(const char* name) const;
	void removeReferee(const char* name);

	friend ostream& operator<<(ostream& os, const Association& association)
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

private:
	League** leagues;
	int numberOfLeagues;
	int sizeLeagues;
	Referee** referees;
	int numberOfReferees;
	int sizeReferees;

	Association(const Association& other);	// Cannot duplicate an association
	Association& operator=(const Association& other);

	int getLeagueIndex(const char* name) const;
	int getRefereeIndex(const char* name) const;

};

#endif // !_ASSOCIATION_H
