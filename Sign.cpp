#define _CRT_SECURE_NO_WARNINGS
#include"Sign.h"
//��ݵ�ѡ�񣺿��Ա���ռ���
int Menu() {
	cout << "*****���˵�******" << endl << endl;
	cout << "****0.�˳�*******" << endl << endl;
	cout << "****1.���Ա*****" << endl << endl;
	cout << "****2.�ռ�*****" << endl << endl;
	cout << "*****************" << endl << endl;
	int a;
	cout << "��ѡ��";
	cin >> a;
	switch (a)
	{
	case 0:exit(0);
		break;
	case 1:Sleep(1000);
		system("cls");
		PostSign(); break;
	case 2:Sleep(1000);
		system("cls");
		ReceSign(); break;
	default:cout << "*������󣬵ȴ�����ѡ��*" << endl;
		Sleep(1000);
		system("cls");
		Menu();
		break;
	}
	return 0;
}

int PostSign() {
	int id, i;
	int num;
	string password;
	cout << "*****���Ա��¼����*****" << endl << endl;
	cout << "*****0.�˳�*************" << endl << endl;
	cout << "*****1.�����˺�����*****" << endl << endl;
	cout << "************************" << endl << endl;
	cout << "�������:";
	cin >> num;
	switch (num) {
	case 0:Sleep(1000);
		system("cls");
		Menu(); break;
	case 1:Sleep(1000);
		system("cls");
		cout << "***�����˺��������***" << endl << endl;
		cout << "******�������˺�******" << endl;
		cin >> id;
		cout << endl;
		cout << "******����������******" << endl;
		cin >> password;
		cout << endl;
		break;
	default:cout << "*�������,�ȴ���������ѡ��*" << endl;
		Sleep(1000);
		system("cls");
		PostSign();
		break;
	}
	for (i = 0; i < 100; i++) {
		if (id == postman[i]->getPostId()) {
			if (password == postman[i]->getPassWord()) {
				cout << "*��¼�ɹ�*" << endl;
				Sleep(1000);
				system("cls");
				Work();
			}
			else {
				cout << "*�������,���µ�¼*" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
		}
	}
	if (i == 100) {
		cout << "*�˺Ų�����,��ȴ���������ѡ��*" << endl;
		Sleep(1000);
		system("cls");
	}
	return 0;
}

int ReceSign() {
	Check();
	cout << "*�ȴ��������˵�*" << endl;
	Sleep(1000);
	system("cls");
	Menu();
	return 0;
}

int Work() {
	int choice;
	cout << "******���Ա��������******" << endl << endl;
	cout << "****0.�˳�,�����ϲ����***" << endl << endl;
	cout << "****1.������************" << endl << endl;
	cout << "****2.��ѯ��ݹ�ʹ�����**" << endl << endl;
	cout << "****3.�����************" << endl << endl;
	cout << "****4.����Ƿ�ʱ********" << endl << endl;
	cout << "**************************" << endl << endl;
	cout << "****������ѡ�";
	cin >> choice;
	switch (choice) {
	case 0:Sleep(1000);
		system("cls");
		PostSign(); break;
	case 1:Sleep(1000);
		system("cls");
		Put(); break;
	case 2:Sleep(1000);
		system("cls");
		checkBox(); break;
	case 3:Sleep(1000);
		system("cls"); checkGoods(); break;
	case 4:Sleep(1000);
		system("cls");
		checkOvertime();
		break;
	default:cout << "������󣬵ȴ���������" << endl;
		Sleep(1000);
		system("cls");
		Work();
		break;
	}
	return 0;
}