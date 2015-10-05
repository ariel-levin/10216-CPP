#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
using namespace std;

class Person
{
public:
	Person(const char* name, int age);
	Person(const Person& other);
	~Person();
	Person& operator=(const Person& other);

	const char* getName() const;
	void setName(const char* name);

	int getAge() const;
	void setAge(int age);

	friend ostream& operator<<(ostream& os, const Person& league)
	{
		os << "No Implementation" << std::endl;
		return os;
	}


private:
	char* name;
	int age;


};


#endif // !_PERSON_H
