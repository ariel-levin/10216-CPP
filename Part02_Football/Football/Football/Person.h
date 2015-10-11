#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
using namespace std;

class Person
{
public:
	Person(const char* name, int age);
	Person(const Person& other);
	virtual ~Person();
	virtual Person& operator=(const Person& other);

	bool operator==(const Person& other) const;

	const char* getName() const;
	void setName(const char* name);

	int getAge() const;
	void setAge(int age);

	int getId() const;

	virtual void toOs(ostream& os) const {};
	friend ostream& operator<<(ostream& os, const Person& person);

private:
	char* name;
	int age;
	int id;

	static int counter;
};

#endif // !_PERSON_H
