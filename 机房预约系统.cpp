#include<iostream>
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using  namespace std;
//进入管理员的子菜单
void managerMeun(Identity * &manager)
{

	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerso();
		}
		else if (select == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showComper();
		}
		else if(select==4)//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//，参数一是 操作的文件名字，参数2是身份的类型
void LoginIn(string  filename, int type)
{
	Identity* person = NULL;//复习多态，父类指针指向子类对象 多态内容
	//接下来是读文件
	ifstream ifs;
	ifs.open(filename, ios::in);//以读的状态来读取文档
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	if (type == 1)//学生的
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名字" << endl;

	cin >> name;

	cout << "请输入密码" << endl;

	cin >> pwd;

	if (type == 1)//学生的
	{
		int fId;//代表从文件中读出的
		string fName;
		string fPwd;
		while (ifs>>fId&&ifs>>fName&&ifs>>fPwd)//ifs 返回值是bool类型 ifs>>将文本中的东西读入》》的右边 空格分割
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证成功" << endl;
				system("pause");
				system("cls");//清屏是清除当前调用函数所显示的数据而不是整个main函数
				person = new Student(id,name,pwd);
				//进入到学生的子菜单；创立new 的意义是，如果没有new 就没有实例化对象，也就用不到类的东西
				return ;
			}

		}

	}
	else if (type == 2)//老师的
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师认证成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);//之后进入教师菜单  
				
				return;
			}
		}

	}
	else if (type == 3)//管理员的
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员认证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);//之后进入管理员菜单
				managerMeun(person);
				return;
			}

		}
	}
	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
}
int main()
{
	int select = 0;//用于接收
	while (true)
	{
		cout << "=========欢迎来到选课系统========" << endl;
		cout << "请输入您的身份" << endl;
		cout << "1. 学生代表" << endl;
		cout << "2. 老师" << endl; 
		cout << "3. 管理员" << endl;
		cout << "0. 退出" << endl;
		cout << "------------------------" << endl;
		cout << "请输入您的选择" << endl;
		cin >> select;//等待输入
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;//学生身份

		case 2:
			LoginIn(TEACHER_FILE, 2);
 
			break;//老师身份
		case 3:
			LoginIn(ADMIN_FILE,3);
			break;//管理员身份
		case 0:
			cout << "欢迎使用下一次使用，再见" << endl;
			system("pause");
			return 0;
			break;//退出系统
		default:
			cout << "输入数值不对" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
system("pause");
	return 0;

}