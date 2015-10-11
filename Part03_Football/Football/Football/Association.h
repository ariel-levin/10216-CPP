#ifndef _ASSOCIATION_H
#define _ASSOCIATION_H

#include <iostream>
#include <vector>
using namespace std;

#include "League.h"
#include "Referee.h"


class Association
{
public:
	Association(int numberOfLeagues, int numberOfReferees);

	void start();

	void addLeague(const League& league);
	const League& getLeague(const char* name) const;
	void removeLeague(const char* name);

	void addReferee(const Referee& referee);
	const Referee& getReferee(const char* name) const;
	void removeReferee(const char* name);

	int getSizeLeagues() const;
	int getSizeReferees() const;

	friend ostream& operator<<(ostream& os, const Association& association);

private:
	vector<League> leagues;
	int numberOfLeagues;
	vector<Referee> referees;
	int numberOfReferees;

	Association(const Association& other);	// Cannot duplicate an association
	Association& operator=(const Association& other);

	vector<League>::const_iterator getLeagueItr(const char* name) const;
	vector<Referee>::const_iterator getRefereeItr(const char* name) const;

};

#endif // !_ASSOCIATION_H
