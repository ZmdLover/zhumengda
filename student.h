#pragma once
#include"identity.h"
using namespace std;
class Student :public Identity
{
public:
	Student();
	
	Student(int id, string name, string pwd);

	virtual void operMenu();

	void applyOeder();//����ԤԼ

	void showMyorder();//�鿴�Լ�ԤԼ

	void showAllOrder();//�鿴����ԤԼ
	
	void cancelOrder();//ȡ���Լ���ԤԼ
	int m_Id;
};