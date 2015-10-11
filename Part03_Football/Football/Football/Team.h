#ifndef _TEAM_H
#define _TEAM_H

#include <iostream>
#include <vector>
using namespace std;

#include "StaffMember.h"
#include "Stadium.h"

class Team
{
public:
	Team(const Stadium& stadium, int numberOfStaff, const string& name);
	Team(const Team& other);
	~Team();
	Team& operator=(const Team& other);

	const Team& operator+=(const StaffMember& staffMember);
	const Team& operator-=(const StaffMember& staffMember);
	StaffMember& operator[](int index) const;
	StaffMember& operator[](int index);

	void addStaff(const StaffMember& staffmember);
	const StaffMember* getStaffMember(const string& name) const;
	void removeStaffMember(const string& name);

	const Stadium getStadium() const;
	void setStadium(const Stadium& stadium);

	const string& getName() const;
	void setName(const string& name);

	int getPlayerCounter() const;
	int getSize() const;

	friend ostream& operator<<(ostream& os, const Team& team);

private:
	string name;
	int numberOfStaff;
	int playerCounter;
	vector<StaffMember*> staff;
	Stadium stadium;

	void setStaff(vector<StaffMember*> staff, int numberOfStaff);
	vector<StaffMember*>::const_iterator getStaffMemberItr(const string& name) const;
	void removeStaffMemberByItr(const vector<StaffMember*>::const_iterator& itr);

};

#endif // !_TEAM_H
