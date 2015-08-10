#ifndef __COACH_H
#define __COACH_H

#include <iostream>
#include "employee.h"

using namespace std;


class Coach : public Employee
{
public:
	Coach(const Employee& emp);

	friend ostream& operator<<(ostream& os, const Coach& c);

private:

};

#endif	// __COACH_H
