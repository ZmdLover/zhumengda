#include<iostream>
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using  namespace std;
//�������Ա���Ӳ˵�
void managerMeun(Identity * &manager)
{

	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerso();
		}
		else if (select == 3)//�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComper();
		}
		else if(select==4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//������һ�� �������ļ����֣�����2����ݵ�����
void LoginIn(string  filename, int type)
{
	Identity* person = NULL;//��ϰ��̬������ָ��ָ��������� ��̬����
	//�������Ƕ��ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);//�Զ���״̬����ȡ�ĵ�
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	if (type == 1)//ѧ����
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;

	cin >> name;

	cout << "����������" << endl;

	cin >> pwd;

	if (type == 1)//ѧ����
	{
		int fId;//������ļ��ж�����
		string fName;
		string fPwd;
		while (ifs>>fId&&ifs>>fName&&ifs>>fPwd)//ifs ����ֵ��bool���� ifs>>���ı��еĶ������롷�����ұ� �ո�ָ�
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤�ɹ�" << endl;
				system("pause");
				system("cls");//�����������ǰ���ú�������ʾ�����ݶ���������main����
				person = new Student(id,name,pwd);
				//���뵽ѧ�����Ӳ˵�������new �������ǣ����û��new ��û��ʵ��������Ҳ���ò�����Ķ���
				return ;
			}

		}

	}
	else if (type == 2)//��ʦ��
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);//֮������ʦ�˵�  
				
				return;
			}
		}

	}
	else if (type == 3)//����Ա��
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);//֮��������Ա�˵�
				managerMeun(person);
				return;
			}

		}
	}
	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");
}
int main()
{
	int select = 0;//���ڽ���
	while (true)
	{
		cout << "=========��ӭ����ѡ��ϵͳ========" << endl;
		cout << "�������������" << endl;
		cout << "1. ѧ������" << endl;
		cout << "2. ��ʦ" << endl; 
		cout << "3. ����Ա" << endl;
		cout << "0. �˳�" << endl;
		cout << "------------------------" << endl;
		cout << "����������ѡ��" << endl;
		cin >> select;//�ȴ�����
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;//ѧ�����

		case 2:
			LoginIn(TEACHER_FILE, 2);
 
			break;//��ʦ���
		case 3:
			LoginIn(ADMIN_FILE,3);
			break;//����Ա���
		case 0:
			cout << "��ӭʹ����һ��ʹ�ã��ټ�" << endl;
			system("pause");
			return 0;
			break;//�˳�ϵͳ
		default:
			cout << "������ֵ����" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
system("pause");
	return 0;

}