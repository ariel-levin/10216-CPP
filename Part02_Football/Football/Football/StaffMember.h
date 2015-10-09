#ifndef _STAFFMEMBER_H
#define _STAFFMEMBER_H

#include <iostream>
using namespace std;

#include "Person.h"

class StaffMember: public Person
{
public:
	StaffMember(const Person& person, int sallary, int yearsOfExperience);// : Person(person), sallary(sallary), yearsOfExperience(yearsOfExperience){};
	
	int getSallary() const;
	void setSallary(int sallary);

	int getYearsOfExperience() const;
	void setYearsOfExperience(int yearsOfExperience);
	virtual void toOs(ostream& os) const;

	//friend ostream& operator<<(ostream& os, const StaffMember& staffMember)
	//{
	//	os << (Person)staffMember << endl;
	//	os << "Sallary: " << staffMember.sallary << ", Years Of Experience: " << staffMember.yearsOfExperience << endl;
	//	return os;
	//}

private:
	int sallary;
	int yearsOfExperience;
};


#endif // !_STAFFMEMBER_H
