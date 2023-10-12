#pragma once
#include"identity.h"

class Manager:public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	virtual void operMenu();

	void addPerson();

	void showPerso();

	void showComper();

	void cleanFile();
};