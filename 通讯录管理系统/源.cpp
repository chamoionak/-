#include<iostream>
#include<cstdlib>
using namespace std;
#define max 2
struct person
{
	string name;
	string gender;
	int age;
	string tele;
};
struct book
{
	struct person list[max];
	int size = 0;
};
void menu();
void input(book*add);
void output(book* add);
int judge(book* add,string aname);
void find(book* add,int i);
void delate(book* add, int i);
void write(book* add, int i);
void abolish(book* add);
int main()
{
	cout << "--------------------------------------------------------------"<<endl;
	cout << "                   正在登陆通讯录管理系统"<<endl;
	cout << "--------------------------------------------------------------"<<endl;
	cout << "                         是否登陆 "<<endl;
	cout << "                           1.是"<<endl;
	cout << "                           2.否"<<endl;
	cout << "--------------------------------------------------------------"<<endl;
	int start = 0;
	int option = -1;
	cin >> start;
	system("cls");
	int op;
	book ad;
	if (start == 1)
	{
		menu();
		while (option != 0)
		{
			cin >> op;
			switch (op)
			{
			case 1:
			{
				input(&ad);
				break;
			}
			case 2:
			{
				output(&ad);
				break;
			}
			case 3:
			{
				string bname;
				cout << "输入查找的对象：";
				cin >> bname;
				find(&ad, judge(&ad, bname));
				break;
			}
			case 4:
			{
				string cname;
				cout << "输入要删除的对象: ";
				cin >> cname;
				delate(&ad, judge(&ad, cname));
				break;
			}
			case 5:
			{
				string dname;
				cout << "输入要修改的对象: ";
				cin >> dname;
				write(&ad, judge(&ad, dname));
				break;
			}
			case 6:
			{
				abolish(&ad);
				break;
			}
			default:
			{
				cout << "--------------------------------------------------------------" << endl;
				cout << "                   正在退出通讯录管理系统" << endl;
				cout << "--------------------------------------------------------------" << endl;
				cout << "                   通讯录管理系统退出成功" << endl;
				cout << "--------------------------------------------------------------" << endl;
				exit(0);
			}
			}
		}
	}
	else if(start==2)
	{
	    cout << "退出成功";
		system("pause");
	}
	else
	{
		cout << "不存在！"<<endl;
	}
	return 0;
}
void menu()
{
	cout << "--------------------------------------------------------------" << endl;
	cout << "                         通讯录管理系统" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "                          1.添加联系人"<<endl;
	cout << "                          2.显示联系人" << endl;
	cout << "                          3.查找联系人"<< endl;
	cout << "                          4.删除联系人"<< endl;
	cout << "                          5.修改联系人"<< endl;
	cout << "                          6.清空联系人"<< endl;
	cout << "                          7.退出通讯录"<<endl;
	cout << "--------------------------------------------------------------" << endl;
}
void input(book* add)
{
	if (add->size == max)
	{
		cout << "通讯录已满";
	}
	else
	{
		string inname;
		string ingender;
		int inage;
		string intele;
		cout << "第" << (add->size) + 1 << "位联系人"<<endl;

		cout << "输入姓名: ";
		cin >> inname;
		add->list[add->size].name = inname;

		cout << "输入性别: ";
		cin >> ingender;
		add->list[add->size].gender = ingender;

		cout << "输入年龄: ";
		cin >> inage;
		add->list[add->size].age = inage;

		cout << "输入电话号码: ";
		cin >> intele;
		add->list[add->size].tele = intele;
		add->size++;
	}
	system("pause");
	system("cls");
	menu();
}
void output(book* add)
{
	for (int i = 0; i < add->size; ++i)
	{
		cout << "第"<<i+1 << "位联系人信息：" << endl;
		cout << "姓名" << add->list[i].name << endl;
		cout << "性别" << add->list[i].gender << endl;
		cout << "年龄" << add->list[i].age << endl;
		cout << "电话号码" << add->list[i].tele << endl;
	}
	cout << "显示完毕" << endl;
	system("pause");
	system("cls");
	menu();
}
int judge(book* add,string aname)
{
	for (int i = 0; i < add->size; ++i)
	{
		if (aname == add->list[i].name)
		{
			return i;
		}
	}
	return -1;
}
void find(book* add,int i)
{
	if (i == -1)
	{
		cout << "查无此人";
	}
	else
	{
		cout << "第" << i + 1 << "位联系人信息：" << endl;
		cout << "姓名" << add->list[i].name << endl;
		cout << "性别" << add->list[i].gender << endl;
		cout << "年龄" << add->list[i].age << endl;
		cout << "电话号码" << add->list[i].tele << endl;
	}
	system("pause");
	system("cls");
	menu();
}
void delate(book* add, int i)
{
	int a = 0;
	cout << "确定删除" << add->list[i].name << "联系人？"<<endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	cin >> a;
	if (a == 1)
	{
		add->list[i] = add->list[i + 1];
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "已经取消删除" << endl;
	}
	system("pause");
	system("cls");
	menu();
}
void write(book* add, int i)
{
	cout << "第" << i + 1 << "位联系人信息：" << endl;
	cout << "姓名" << add->list[i].name << endl;
	cout << "性别" << add->list[i].gender << endl;
	cout << "年龄" << add->list[i].age << endl;
	cout << "电话号码" << add->list[i].tele << endl;
	cout << "修改哪一项？" << endl;
	cout << "1.姓名" << endl;
	cout << "2.性别" << endl;
	cout << "3.年龄" << endl;
	cout << "4.电话号码" << endl;
	int aaa = 0;
	cin >> aaa;
	switch (aaa)
	{
	case 1: 
	{
		cout << "请修改姓名：";
		string aname;
		cin >> aname;
		add->list[i].name = aname;
		break;
	}
	case 2:
	{
		cout << "请修改性别：";
		string agender;
		cin >> agender;
		add->list[i].gender = agender;
		break;
	}
	case 3:
	{
		cout << "请修改年龄：";
		int aage;
		cin >> aage;
		add->list[i].age = aage;
		break;
	}
	case 4:
	{
		cout << "请修改电话号码：";
		string atele;
		cin >> atele;
		add->list[i].tele = atele;
		break;
	}
	}
	system("pause");
	system("cls");
	menu();
}
void abolish(book* add)
{
	add->size = 0;
	system("pause");
	system("cls");
	menu();
}