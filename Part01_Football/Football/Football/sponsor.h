#ifndef __SPONSOR_H
#define __SPONSOR_H

#include <iostream>
#include <ctime>

using namespace std;


class Sponsor
{
public:
	Sponsor(int investAmount, const tm& startDate, const tm* endDate = nullptr);
	Sponsor(const Sponsor& other);
	~Sponsor();

	const Sponsor& operator=(const Sponsor& other);

	void setInvestAmount(int investAmount);
	void setEndDate(const tm& endDate);

	int getInvestAmount() const { return investAmount; };
	const tm& getStartDate() const { return startDate; };
	const tm* getEndDate() const { return endDate; };

	friend ostream& operator<<(ostream& os, const Sponsor& s);

private:
	int investAmount;
	tm startDate;
	tm* endDate;

};

#endif	// __SPONSOR_H