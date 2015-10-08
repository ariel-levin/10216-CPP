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
	// TODO: insert return statement here
}

const Team& Team::operator-=(const StaffMember& staffMember)
{
	// TODO: insert return statement here
}

void Team::addStaff(const StaffMember& staffmember)
{

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
	if (index != -1)
	{
		if (numberOfStaff == 1)
		{
			delete[] staff;
		}
		else 
		{
			StaffMember** tmp = new StaffMember*[numberOfStaff - 1];
			for (int i = 0; i < index; i++)
			{
				tmp[i] = staff[i];
			}
			for (int i = index+1; i < numberOfStaff; i++)
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

void Team::setStaff(StaffMember*const* staff, int numberOfStaff)
{
	delete[] this->staff;
	this->staff = new StaffMember*[numberOfStaff];
	for (int i = 0; i < numberOfStaff; i++)
	{
		(this->staff)[i] = staff[i];
	}
}

int Team::getStaffMemberIndex(const char * name) const
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
