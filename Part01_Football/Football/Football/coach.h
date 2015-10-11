#ifndef __COACH_H
#define __COACH_H

#include <iostream>
#include "employee.h"

using namespace std;


class Coach : public Employee
{
public:
	Coach(const Employee& emp, int seniority);

	friend ostream& operator<<(ostream& os, const Coach& c);

	void setSeniority(int seniority);	
	int getSeniority() const			{ return seniority; };

private:
	int seniority;
};

#endif	// __COACH_H
