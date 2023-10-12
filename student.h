#pragma once
#include"identity.h"
using namespace std;
class Student :public Identity
{
public:
	Student();
	
	Student(int id, string name, string pwd);

	virtual void operMenu();

	void applyOeder();//申请预约

	void showMyorder();//查看自己预约

	void showAllOrder();//查看所有预约
	
	void cancelOrder();//取消自己的预约
	int m_Id;
};