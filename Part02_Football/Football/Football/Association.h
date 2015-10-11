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

	friend ostream& operator<<(ostream& os, const Association& association);

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
