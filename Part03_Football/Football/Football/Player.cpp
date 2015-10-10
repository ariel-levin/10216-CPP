#include "Player.h"

Player::Player(const StaffMember& staffMember, Position position, int number) : StaffMember(staffMember)
{
	this->position = position;
	this->number = number;
}

Player::Position Player::getPosition() const
{
	return position;
}

void Player::setPosition(Position position)
{
	this->position = position;
}

int Player::getNumber() const
{
	return number;
}

void Player::setNumber(int number)
{
	if (number > 0)
	{
		this->number = number;
	}
}

void Player::toOs(ostream & os) const
{
	StaffMember::toOs(os);
	os << "Position: " << position << ", Number: " << number << endl;
}

StaffMember* Player::clone() const
{
	return new Player(*this);
}
