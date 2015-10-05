#ifndef _COACH_H
#define _COACH_H

#include <iostream>
using namespace std;

#include "StaffMember.h"

class Coach: virtual public StaffMember
{
public:
	enum Experties
	{
		HEAD,
		GOALKEEPER,
		ASSISTANT,
		FITNESS,
		KICKS
	};

	Coach(const StaffMember& staffMember, Experties experties);

	Experties getExperties() const;
	void setExperties(Experties experties);

	friend ostream& operator<<(ostream& os, const Coach& coach)
	{
		os << "No Implementation" << std::endl;
		return os;
	}

private:
	Experties experties;


};
#endif // !_COACH_H
