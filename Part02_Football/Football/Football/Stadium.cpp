#pragma warning( disable : 4996 )

#include "Stadium.h"

Stadium::Stadium(const char* name, int numberOfSeats, char* location) : name(NULL), location(NULL)
{
	setName(name);
	this->numberOfSeats = numberOfSeats;
	setLocation(location);
}

Stadium::Stadium(const Stadium& other) : name(NULL), location(NULL)
{
	*this = other;
}

Stadium::~Stadium()
{
	delete[] name;
	delete[] location;
}

Stadium& Stadium::operator=(const Stadium& other)
{
	if (this != &other)
	{
		setName(other.name);
		numberOfSeats = other.numberOfSeats;
		setLocation(other.location);
	}
	return *this;
}

const char* Stadium::getName() const
{
	return name;
}

void Stadium::setName(const char* name)
{
	if (this->name != name)
	{
		delete[] this->name;
		this->name = strdup(name);
	}
}

int Stadium::getNumberOfSeats() const
{
	return numberOfSeats;
}

void Stadium::setNumberOfSeats(int numberOfSeats)
{
	this->numberOfSeats = numberOfSeats;
}

const char* Stadium::getLocation()
{
	return location;
}

void Stadium::setLocation(const char* location)
{
	if (this->location != location)
	{
		delete[] this->location;
		this->location = strdup(location);
	}
}
