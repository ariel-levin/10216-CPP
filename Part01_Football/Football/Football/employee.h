#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include "person.h"

using namespace std;


class Employee : public Person
{
public:
	Employee(const Person& person, int salary, int bonus);
	virtual ~Employee();

	const Employee& operator++();
	bool operator<(const Employee& emp);
	bool operator>(const Employee& emp);

	void setSalary(int salary);
	void setBonus(int bonus);

	int getSalary() const { return salary; };
	int getBonus() const { return bonus; };

	friend ostream& operator<<(ostream& os, const Employee& e);

private:
	int salary;
	int bonus;

};

#endif	// __EMPLOYEE_H