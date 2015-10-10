#ifndef _TEAM_H
#define _TEAM_H

#include <iostream>
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

	int getSize() const;
	int getPlayerCounter() const;

	friend ostream& operator<<(ostream& os, const Team& team)
	{
		os << "Team name: " << team.name << ", Staff size: " << team.size << "/" << team.numberOfStaff << endl;
		os << "Stadium:" << endl << team.stadium << endl;
		os << "Staff Members:" << endl;
		for (int i = 0; i < team.size; i++)
		{
			os << *team.staff[i] << endl;
		}
		return os;
	}

private:
	string name;
	int numberOfStaff;
	int size;
	int playerCounter;
	StaffMember** staff;
	Stadium stadium;

	void setStaff(StaffMember** staff, int size, int numberOfStaff);
	int getStaffMemberIndex(const string& name) const;
	void removeStaffMemberByIndex(int index);

};

#endif // !_TEAM_H
