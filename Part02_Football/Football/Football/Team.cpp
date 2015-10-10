#pragma warning( disable : 4996 )

#include "Team.h"
#include "Player.h"


Team::Team(const Stadium& stadium, int numberOfStaff, const char* name) : stadium(stadium)
{
	this->numberOfStaff = numberOfStaff;
	setName(name);
	this->staff = new StaffMember*[numberOfStaff];
	this->size = 0;
	this->playerCounter = 0;
}

Team::Team(const Team& other) : name(NULL), stadium(other.stadium), staff(NULL)
{
	*this = other;
}

Team::~Team()
{
	delete[] name;
	for (int i = 0; i < size; i++)
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
		size = other.size;
		playerCounter = other.playerCounter;
		setStaff(other.staff, other.size, other.numberOfStaff);
		this->stadium = other.stadium;
	}
	return *this;
}

const Team& Team::operator+=(const StaffMember& staffMember)
{
	if (size < numberOfStaff)
	{
		staff[size] = staffMember.clone();
		++size;

		if (typeid(staffMember) == typeid(Player))
		{
			++playerCounter;
		}
	}
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
	if (index >= 0 && index < size)
	{
		if (typeid(staff[index]) == typeid(Player))
		{
			--playerCounter;
		}

		delete staff[index];
		for (int i = index; i < size-1; i++)
		{
			staff[i] = staff[i+1];
		}
		--size;
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

int Team::getSize() const
{
	return size;
}

int Team::getPlayerCounter() const
{
	return playerCounter;
}

void Team::setStaff(StaffMember** staff, int size, int numberOfStaff)
{
	for (int i = 0; i < size; i++)
	{
		delete staff[i];
	}
	delete[] this->staff;
	if (size == 0)
	{
		this->staff = NULL;
	}
	else
	{ 
		this->staff = new StaffMember*[numberOfStaff];
		for (int i = 0; i < size; i++)
		{
			this->staff[i] = staff[i]->clone();
		}
	}
}

int Team::getStaffMemberIndex(const char* name) const
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp((*staff[i]).getName(), name) == 0)
		{
			return i;
		}
	}
	return -1;
}