#pragma warning( disable : 4996 )

#include "Team.h"
#include "Player.h"
#include "StaffMember.h"


Team::Team(const Stadium& stadium, int numberOfStaff, const string& name) : stadium(stadium)
{
	this->numberOfStaff = numberOfStaff;
	setName(name);
	this->playerCounter = 0;
}

Team::Team(const Team& other) : stadium(other.stadium)
{
	*this = other;
}

Team::~Team()
{
	vector<StaffMember*>::iterator  itr = staff.begin();
	vector<StaffMember*>::iterator  itrEnd = staff.end();

	StaffMember* temp;
	for ( ; itr != itrEnd; ++itr)
	{
		temp = *itr;
		delete temp;
	}

	staff.clear();
}

Team& Team::operator=(const Team& other)
{
	if (this != &other)
	{
		setName(other.name);
		numberOfStaff = other.numberOfStaff;
		playerCounter = other.playerCounter;
		setStaff(other.staff, other.numberOfStaff);
		this->stadium = other.stadium;
	}
	return *this;
}

const Team& Team::operator+=(const StaffMember& staffMember)
{
	if (getSize() < numberOfStaff)
	{
		staff.push_back(staffMember.clone());

		if (typeid(staffMember) == typeid(Player))
		{
			++playerCounter;
		}
	}
	return *this;
}

const Team& Team::operator-=(const StaffMember& staffMember)
{
	vector<StaffMember*>::iterator  itr = this->staff.begin();
	vector<StaffMember*>::iterator  itrEnd = this->staff.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getId() == staffMember.getId())
		{
			removeStaffMemberByItr(itr);
			break;
		}
	}
	return *this;
}

StaffMember& Team::operator[](int index) const
{
	return *staff[index];
}

StaffMember& Team::operator[](int index)
{
	return *staff[index];
}

void Team::addStaff(const StaffMember& staffmember)
{
	*this += staffmember;
}

const StaffMember* Team::getStaffMember(const string& name) const
{
	vector<StaffMember*>::const_iterator itr = getStaffMemberItr(name);
	if (itr != staff.end())
		return *itr;
	else
		return NULL;
}

void Team::removeStaffMember(const string& name)
{
	vector<StaffMember*>::const_iterator itr = getStaffMemberItr(name);
	removeStaffMemberByItr(itr);
}

void Team::removeStaffMemberByItr(const vector<StaffMember*>::const_iterator& itr)
{
	if (itr != staff.end())
	{
		StaffMember* tmp = *itr;
		delete tmp;
		staff.erase(itr);
	}
}

const Stadium Team::getStadium() const
{
	return stadium;
}

void Team::setStadium(const Stadium& stadium)
{
	this->stadium = stadium;
}

const string& Team::getName() const
{
	return name;
}

void Team::setName(const string& name)
{
	this->name = name;
}

int Team::getPlayerCounter() const
{
	return playerCounter;
}

int Team::getSize() const
{
	return (int)staff.size();
}

void Team::setStaff(vector<StaffMember*> staff, int numberOfStaff)
{
	// delete
	vector<StaffMember*>::iterator  itr = this->staff.begin();
	vector<StaffMember*>::iterator  itrEnd = this->staff.end();

	StaffMember* temp;
	for (; itr != itrEnd; ++itr)
	{
		temp = *itr;
		delete temp;
	}
	this->staff.clear();

	// clone
	for (int i = 0; i < (int)staff.size(); i++)
	{
		this->staff.push_back(staff[i]->clone());
	}
}

vector<StaffMember*>::const_iterator Team::getStaffMemberItr(const string& name) const
{
	vector<StaffMember*>::const_iterator  itr = staff.begin();
	vector<StaffMember*>::const_iterator  itrEnd = staff.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName().compare(name) == 0)
		{
			return itr;
		}
	}
	return itrEnd;
}