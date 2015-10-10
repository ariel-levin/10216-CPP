#include "Coach.h"

Coach::Coach(const StaffMember& staffMember, Expertise experties) : StaffMember(staffMember)
{
	this->expertise = experties;
}

Coach::Expertise Coach::getExperties() const
{
	return expertise;
}

void Coach::setExperties(Expertise experties)
{
	this->expertise = experties;
}

void Coach::toOs(ostream & os) const
{
	StaffMember::toOs(os);
	os << "Expertise: " << expertise << endl;
}

StaffMember* Coach::clone() const
{
	return new Coach(*this);
}
