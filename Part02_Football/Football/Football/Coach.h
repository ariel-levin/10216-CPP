#ifndef _COACH_H
#define _COACH_H

#include <iostream>
using namespace std;

#include "StaffMember.h"

class Coach: virtual public StaffMember
{
public:
	enum Expertise
	{
		HEAD,
		GOALKEEPER,
		ASSISTANT,
		FITNESS,
		KICKS
	};

	Coach(const StaffMember& staffMember, Expertise experties);

	Expertise getExperties() const;
	void setExperties(Expertise experties);

	virtual void toOs(ostream& os) const;

	virtual StaffMember* clone() const;

private:
	Expertise expertise;


};
#endif // !_COACH_H
