#include"manager.h"
Manager::Manager()
{}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd; 
}

void Manager::operMenu()
{
	cout << "��ӭ����Ա" << this->m_Name << "����" << endl;
	cout << "_________________________________________" << endl;
	cout << "1.����˺�" << endl;
	cout << "2.�鿴�˺�" << endl;
	cout << "3.�鿴����" << endl;
	cout << "4.���ԤԼ" << endl;
	cout << "0.ע���˺�" << endl;
	cout << "____________________________________________" << endl;
	cout << "��ѡ����Ĳ���" << endl;
}

void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;
	string tip;//ְ���ź�ѧ��֮���
	ofstream ofs;//�����

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
	}
	else if(select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����";
	}
	ofs.open(fileName, ios::out | ios::app);//�ڵ�ǰ�ļ�׷��

	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << " " << pwd<<endl;
	cout << "��ӳɹ���" << endl;
	system("pause");//���ᣬ�����������
	system("cls");
	ofs.close();
}

void Manager::showPerso()
{}

void Manager::showComper()
{}

void Manager::cleanFile()
{}