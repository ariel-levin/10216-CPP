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

	void addStaff(const StaffMember& staffmember);
	const StaffMember* getStaffMember(const char* name) const;
	void removeStaffMember(const char* name);

	const Stadium getStadium() const;
	void setStadium(const Stadium& stadium);

	const char* getName() const;
	void setName(const char* name);

	friend ostream& operator<<(ostream& os, const Team& team)
	{
		os << "Team name: " << team.name << ", Number of Staff: " << team.numberOfStaff << endl;
		os << "Stadium:" << endl << team.stadium << endl;
		os << "Staff Members:" << endl;
		for (int i = 0; i < team.size; i++)
		{
			os << *team.staff[i] << endl;
		}
		return os;
	}

private:
	char* name;
	int numberOfStaff;
	int size;
	StaffMember** staff;
	Stadium stadium;

	void setStaff(StaffMember** staff, int size, int numberOfStaff);
	int getStaffMemberIndex(const char* name) const;
	void removeStaffMemberByIndex(int index);

};

#endif // !_TEAM_H
