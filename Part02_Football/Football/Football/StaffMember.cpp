#include "StaffMember.h"

StaffMember::StaffMember(const Person & person, int sallary, int yearsOfExperience) : Person(person)
{
	this->sallary = sallary;
	this->yearsOfExperience = yearsOfExperience;
}

int StaffMember::getSallary() const
{
	return sallary;
}

void StaffMember::setSallary(int sallary)
{
	this->sallary = sallary;
}

int StaffMember::getYearsOfExperience() const
{
	return yearsOfExperience;
}

void StaffMember::setYearsOfExperience(int yearsOfExperience)
{
	this->yearsOfExperience = yearsOfExperience;
}

void StaffMember::toOs(ostream os) const
{
	os << "Sallary: " << sallary << ", Years Of Experience: " << yearsOfExperience << endl;
}
