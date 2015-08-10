#ifndef __COMPANY_H
#define __COMPANY_H

#include <iostream>
#include "sponsor.h"

using namespace std;


class Company : public Sponsor
{
public:
	Company(const Sponsor& sponsor, int id, const char* name, int numOfEmployees);

	void setName(const char* name);
	void setNumOfEmployees(int numOfEmployees);

	int getId() const { return id; };
	const char* getName() const { return name; };
	int getNumOfEmployees() const { return numOfEmployees; };

	friend ostream& operator<<(ostream& os, const Company& c);

private:
	int id;
	char* name;
	int numOfEmployees;

};

#endif	// __COMPANY_H