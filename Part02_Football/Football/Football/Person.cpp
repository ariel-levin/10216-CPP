#pragma warning( disable : 4996 )

#include "Person.h"

int Person::counter = 0;


Person::Person(const char* name, int age) : name(NULL)
{
	setName(name);
	this->age = age;
	this->id = ++counter;
}

Person::Person(const Person& other) : name(NULL)
{
	*this = other;
}

Person::~Person()
{
	delete[] name;
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		age = other.age;
		setName(other.name);
		id = other.id;
	}
	return *this;
}

bool Person::operator==(const Person& other) const
{
	return this->id == other.id;
}

const char* Person::getName() const
{
	return this->name;
}

void Person::setName(const char* name)
{
	if (this->name != name)
	{
		delete[] this->name;
		this->name = strdup(name);
	}
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
