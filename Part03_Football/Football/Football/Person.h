#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include <iostream>
using namespace std;


class Person
{
public:
	Person(const string& name, int age);
	virtual ~Person() {}

	bool operator==(const Person& other) const;

	const string& getName() const;
	void setName(const string& name);

	int getAge() const;
	void setAge(int age);

	int getId() const;

	virtual void toOs(ostream& os) const {};
	friend ostream& operator<<(ostream& os, const Person& person);

private:
	string name;
	int age;
	int id;

	static int counter;
};

#endif // !_PERSON_H
