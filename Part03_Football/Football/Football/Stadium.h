#ifndef _STADIUM_H
#define _STADIUM_H

#include <string>
#include <iostream>

using namespace std;

class Stadium
{
public:
	Stadium(const string& name, int numberOfSeats, const string& location);

	const string& getName() const;
	void setName(const string& name);

	int getNumberOfSeats() const;
	void setNumberOfSeats(int numberOfSeats);

	const string& getLocation();
	void setLocation(const string& location);

	friend ostream& operator<<(ostream& os, const Stadium& league);

private:
	string name;
	int numberOfSeats;
	string location;

};

#endif // !_STADIUM_H
