#pragma once
#include"identity.h"
class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void operMenu();

	void showALLOrder();

	void vailOrder();

	int m_Empid;
};