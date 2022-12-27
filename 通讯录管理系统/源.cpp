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
	cout << "                   ���ڵ�½ͨѶ¼����ϵͳ"<<endl;
	cout << "--------------------------------------------------------------"<<endl;
	cout << "                         �Ƿ��½ "<<endl;
	cout << "                           1.��"<<endl;
	cout << "                           2.��"<<endl;
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
				cout << "������ҵĶ���";
				cin >> bname;
				find(&ad, judge(&ad, bname));
				break;
			}
			case 4:
			{
				string cname;
				cout << "����Ҫɾ���Ķ���: ";
				cin >> cname;
				delate(&ad, judge(&ad, cname));
				break;
			}
			case 5:
			{
				string dname;
				cout << "����Ҫ�޸ĵĶ���: ";
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
				cout << "                   �����˳�ͨѶ¼����ϵͳ" << endl;
				cout << "--------------------------------------------------------------" << endl;
				cout << "                   ͨѶ¼����ϵͳ�˳��ɹ�" << endl;
				cout << "--------------------------------------------------------------" << endl;
				exit(0);
			}
			}
		}
	}
	else if(start==2)
	{
	    cout << "�˳��ɹ�";
		system("pause");
	}
	else
	{
		cout << "�����ڣ�"<<endl;
	}
	return 0;
}
void menu()
{
	cout << "--------------------------------------------------------------" << endl;
	cout << "                         ͨѶ¼����ϵͳ" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "                          1.�����ϵ��"<<endl;
	cout << "                          2.��ʾ��ϵ��" << endl;
	cout << "                          3.������ϵ��"<< endl;
	cout << "                          4.ɾ����ϵ��"<< endl;
	cout << "                          5.�޸���ϵ��"<< endl;
	cout << "                          6.�����ϵ��"<< endl;
	cout << "                          7.�˳�ͨѶ¼"<<endl;
	cout << "--------------------------------------------------------------" << endl;
}
void input(book* add)
{
	if (add->size == max)
	{
		cout << "ͨѶ¼����";
	}
	else
	{
		string inname;
		string ingender;
		int inage;
		string intele;
		cout << "��" << (add->size) + 1 << "λ��ϵ��"<<endl;

		cout << "��������: ";
		cin >> inname;
		add->list[add->size].name = inname;

		cout << "�����Ա�: ";
		cin >> ingender;
		add->list[add->size].gender = ingender;

		cout << "��������: ";
		cin >> inage;
		add->list[add->size].age = inage;

		cout << "����绰����: ";
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
		cout << "��"<<i+1 << "λ��ϵ����Ϣ��" << endl;
		cout << "����" << add->list[i].name << endl;
		cout << "�Ա�" << add->list[i].gender << endl;
		cout << "����" << add->list[i].age << endl;
		cout << "�绰����" << add->list[i].tele << endl;
	}
	cout << "��ʾ���" << endl;
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
		cout << "���޴���";
	}
	else
	{
		cout << "��" << i + 1 << "λ��ϵ����Ϣ��" << endl;
		cout << "����" << add->list[i].name << endl;
		cout << "�Ա�" << add->list[i].gender << endl;
		cout << "����" << add->list[i].age << endl;
		cout << "�绰����" << add->list[i].tele << endl;
	}
	system("pause");
	system("cls");
	menu();
}
void delate(book* add, int i)
{
	int a = 0;
	cout << "ȷ��ɾ��" << add->list[i].name << "��ϵ�ˣ�"<<endl;
	cout << "1.��" << endl;
	cout << "2.��" << endl;
	cin >> a;
	if (a == 1)
	{
		add->list[i] = add->list[i + 1];
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "�Ѿ�ȡ��ɾ��" << endl;
	}
	system("pause");
	system("cls");
	menu();
}
void write(book* add, int i)
{
	cout << "��" << i + 1 << "λ��ϵ����Ϣ��" << endl;
	cout << "����" << add->list[i].name << endl;
	cout << "�Ա�" << add->list[i].gender << endl;
	cout << "����" << add->list[i].age << endl;
	cout << "�绰����" << add->list[i].tele << endl;
	cout << "�޸���һ�" << endl;
	cout << "1.����" << endl;
	cout << "2.�Ա�" << endl;
	cout << "3.����" << endl;
	cout << "4.�绰����" << endl;
	int aaa = 0;
	cin >> aaa;
	switch (aaa)
	{
	case 1: 
	{
		cout << "���޸�������";
		string aname;
		cin >> aname;
		add->list[i].name = aname;
		break;
	}
	case 2:
	{
		cout << "���޸��Ա�";
		string agender;
		cin >> agender;
		add->list[i].gender = agender;
		break;
	}
	case 3:
	{
		cout << "���޸����䣺";
		int aage;
		cin >> aage;
		add->list[i].age = aage;
		break;
	}
	case 4:
	{
		cout << "���޸ĵ绰���룺";
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