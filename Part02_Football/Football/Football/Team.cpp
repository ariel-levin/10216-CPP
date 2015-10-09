#pragma warning( disable : 4996 )
#include "Team.h"

Team::Team(const Stadium& stadium, int numberOfStaff, const char* name) : stadium(stadium)
{
	this->numberOfStaff = numberOfStaff;
	setName(name);
	this->staff = new StaffMember*[numberOfStaff];
}

Team::Team(const Team& other) : name(NULL), stadium(other.stadium), staff(NULL)
{
	setName(other.name);
	numberOfStaff = other.numberOfStaff;
	setStaff(other.staff, other.numberOfStaff);
}

Team::~Team()
{
	delete[] name;
	for (int i = 0; i < numberOfStaff; i++)
	{
		delete staff[i];
	}
	delete[] staff;
}

Team& Team::operator=(const Team& other)
{
	if (this != &other)
	{
		setName(other.name);
		numberOfStaff = other.numberOfStaff;
		setStaff(other.staff, other.numberOfStaff);
		this->stadium = other.stadium;
	}
	return *this;
}

const Team& Team::operator+=(const StaffMember& staffMember)
{
	addStaff(staffMember);
	return *this;
}

const Team& Team::operator-=(const StaffMember& staffMember)
{
	for (int i = 0; i < numberOfStaff; i++)
	{
		if ((*staff[i]).getId() == staffMember.getId())
		{
			removeStaffMemberByIndex(i);
			break;
		}
	}
	return *this;
}

void Team::addStaff(const StaffMember& staffmember)
{
	StaffMember** tmp = new StaffMember*[numberOfStaff + 1];
	for (int i = 0; i < numberOfStaff; i++)
	{
		tmp[i] = staff[i];
	}
	tmp[numberOfStaff] = new StaffMember(staffmember);
	delete[] staff;
	staff = tmp;
	++numberOfStaff;
}

const StaffMember* Team::getStaffMember(const char* name) const
{
	int i = getStaffMemberIndex(name);
	if (i != -1)
		return staff[i];
	else
		return NULL;
}

void Team::removeStaffMember(const char* name)
{
	int index = getStaffMemberIndex(name);
	removeStaffMemberByIndex(index);
}

void Team::removeStaffMemberByIndex(int index)
{
	if (index >= 0 && index < numberOfStaff)
	{
		if (numberOfStaff == 1)
		{
			delete[] staff;
			staff = NULL;
		}
		else
		{
			StaffMember** tmp = new StaffMember*[numberOfStaff - 1];
			for (int i = 0; i < index; i++)
			{
				tmp[i] = staff[i];
			}
			for (int i = index + 1; i < numberOfStaff; i++)
			{
				tmp[i] = staff[i];
			}
			delete[] staff;
			staff = tmp;
		}
		--numberOfStaff;
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

const char* Team::getName() const
{
	return name;
}

void Team::setName(const char* name)
{
	if (this->name != name)
	{
		delete[] this->name;
		this->name = strdup(name);
	}
}

void Team::setStaff(StaffMember** staff, int numberOfStaff)
{
	delete[] this->staff;
	if (numberOfStaff == 0)
	{
		this->staff = NULL;
	}
	else
	{ 
		this->staff = new StaffMember*[numberOfStaff];
		for (int i = 0; i < numberOfStaff; i++)
		{
			*(this->staff)[i] = *staff[i];
		}
	}
}

int Team::getStaffMemberIndex(const char* name) const
{
	for (int i = 0; i < numberOfStaff; i++)
	{
		if (strcmp((*staff[i]).getName(), name) == 0)
		{
			return i;
		}
	}
	return -1;
}