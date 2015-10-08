#include "Referee.h"

Referee::Referee(const Person & person, Position position) : Person(person)
{
	this->position = position;
}

Referee::Position Referee::getPosition() const
{
	return this->position;
}

void Referee::setPosition(Position position)
{
	this->position = position;
}

void Referee::toOs(ostream os) const
{
	os << "Position: " << position << endl;
}
