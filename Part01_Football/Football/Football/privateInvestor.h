#ifndef __PRIVATE_INVESTOR_H
#define __PRIVATE_INVESTOR_H

#include <iostream>
#include "person.h"
#include "sponsor.h"

using namespace std;


class PrivateInvestor : public Person, public Sponsor
{
public:
	PrivateInvestor(const Person& person, const Sponsor& sponsor);

	friend ostream& operator<<(ostream& os, const PrivateInvestor& pi);

private:


};

#endif	// __PRIVATE_INVESTOR_H