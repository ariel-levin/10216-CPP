#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <ctime>

using namespace std;


class Person
{
public:
	Person(int id, const char* name, const tm& birthdate, const char* country);
	Person(const Person& other);
	virtual ~Person();

	const Person& operator=(const Person& other);

	void setName(const char* name);
	void setCountry(const char* country);

	int getId() const { return id; };
	const char* getName() const { return name; };
	const tm& getBirthdate() const { return birthdate; };
	const char* getCountry() const { return country; };

	friend ostream& operator<<(ostream& os, const Person& p);
	
private:
	int id;
	char* name;
	tm birthdate;
	char* country;

};

#endif	// __PERSON_H