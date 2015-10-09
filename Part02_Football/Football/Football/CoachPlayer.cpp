#include "CoachPlayer.h"

CoachPlayer::CoachPlayer(const Player & player, const Coach & coach) : Player(player), Coach(coach),
	StaffMember(Person(player.getName(), player.getAge()), player.getSallary(), player.getYearsOfExperience())
{

}

StaffMember* CoachPlayer::clone() const
{
	//return nullptr;
	return new CoachPlayer(*this);
}

void CoachPlayer::toOs(ostream& os) const
{
	Player::toOs(os);
	os << "Expertise: " << Coach::getExperties() << endl;
}
