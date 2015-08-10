#ifndef __JUDGE_H
#define __JUDGE_H

#include <iostream>
#include "employee.h"

using namespace std;


class Judge : public Employee
{
public:
	Judge(const Employee& emp);

	friend ostream& operator<<(ostream& os, const Judge& j);

	void whistle() const;
	void yellowCard() const;
	void redCard() const;

private:

};

#endif	// __JUDGE_H
