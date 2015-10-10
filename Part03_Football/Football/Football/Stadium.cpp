#pragma warning( disable : 4996 )

#include "Stadium.h"


Stadium::Stadium(const string& name, int numberOfSeats, const string& location)
{
	setName(name);
	this->numberOfSeats = numberOfSeats;
	setLocation(location);
}

const string& Stadium::getName() const
{
	return name;
}

void Stadium::setName(const string& name)
{
	this->name = name;
}

int Stadium::getNumberOfSeats() const
{
	return numberOfSeats;
}

void Stadium::setNumberOfSeats(int numberOfSeats)
{
	this->numberOfSeats = numberOfSeats;
}

const string& Stadium::getLocation()
{
	return location;
}

void Stadium::setLocation(const string& location)
{
	this->location = location;
}
