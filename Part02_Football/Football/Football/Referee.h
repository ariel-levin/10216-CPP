#ifndef _REFEREE_H
#define  _REFEREE_H

#include <iostream>
using namespace std;

#include "Person.h"

class Referee: public Person
{
public:
	enum Position
	{
		CENTER,
		SIDELINE,
		ASISSTANT
	};

	Referee(const Person& person, Position position);
	
	Position getPosition() const;
	void setPosition(Position position);
	virtual void toOs(ostream& os) const;

private:
	Position position;

};

#endif // !_REFEREE_H
