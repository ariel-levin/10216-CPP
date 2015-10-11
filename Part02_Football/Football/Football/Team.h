#ifndef _TEAM_H
#define _TEAM_H

#include <iostream>
using namespace std;

#include "StaffMember.h"
#include "Stadium.h"

class Team
{
public:
	Team(const Stadium& stadium, int numberOfStaff, const char* name);
	Team(const Team& other);
	~Team();
	Team& operator=(const Team& other);

	const Team& operator+=(const StaffMember& staffMember);
	const Team& operator-=(const StaffMember& staffMember);
	StaffMember& operator[](int index) const;
	StaffMember& operator[](int index);

	void addStaff(const StaffMember& staffmember);
	const StaffMember* getStaffMember(const char* name) const;
	void removeStaffMember(const char* name);

	const Stadium getStadium() const;
	void setStadium(const Stadium& stadium);

	const char* getName() const;
	void setName(const char* name);

	int getSize() const;
	int getPlayerCounter() const;

	friend ostream& operator<<(ostream& os, const Team& team);

private:
	char* name;
	int numberOfStaff;
	int size;
	int playerCounter;
	StaffMember** staff;
	Stadium stadium;

	void setStaff(StaffMember** staff, int size, int numberOfStaff);
	int getStaffMemberIndex(const char* name) const;
	void removeStaffMemberByIndex(int index);

};

#endif // !_TEAM_H
