#pragma warning( disable : 4996 )

#include "Person.h"

int Person::counter = 0;


Person::Person(const string& name, int age)
{
	setName(name);
	this->age = age;
	this->id = ++counter;
}

bool Person::operator==(const Person& other) const
{
	return this->id == other.id;
}

const string& Person::getName() const
{
	return this->name;
}

void Person::setName(const string& name)
{
	this->name = name;
}

int Person::getAge() const
{
	return this->age;
}

void Person::setAge(int age)
{
	this->age = age;
}

int Person::getId() const
{
	return id;
}

ostream& operator<<(ostream& os, const Person& person)
{
	os << "Name: " << person.name << ", Age: " << person.age << endl;
	person.toOs(os);
	return os;
}
