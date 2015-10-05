#pragma warning( disable : 4996 )

#include "Person.h"

Person::Person(const char* name, int age) : name(NULL)
{
	setName(name);
	this->age = age;
}

Person::Person(const Person & other)
{
}

Person::~Person()
{
}

//Person& Person::operator=(const Person & other)
//{
//	// TODO: insert return statement here
//}

const char* Person::getName() const
{
	return nullptr;
}

void Person::setName(const char* name)
{
	if (this->name != name)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

int Person::getAge() const
{
	return 0;
}

void Person::setAge(int age)
{
}
