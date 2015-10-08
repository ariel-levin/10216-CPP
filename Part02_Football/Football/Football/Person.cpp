#pragma warning( disable : 4996 )

#include "Person.h"

Person::Person(const char* name, int age) : name(NULL)
{
	setName(name);
	this->age = age;
}

Person::Person(const Person & other) : name(NULL)
{
	*this = other;
}

Person::~Person()
{
	delete[] name;
}

Person& Person::operator=(const Person & other)
{
	if (this != &other)
	{
		age = other.age;
		setName(other.name);
	}
	return *this;
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
		//this->name = new char[strlen(name) + 1];
		//strcpy(this->name, name);
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
