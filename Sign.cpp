#define _CRT_SECURE_NO_WARNINGS
#include"Sign.h"
//��ݵ�ѡ�񣺿��Ա���ռ���
int Menu() {
	int a;
	while (1)
	{
		cout << "*****���˵�******" << endl << endl;
		cout << "****0.�˳�*******" << endl << endl;
		cout << "****1.���Ա*****" << endl << endl;
		cout << "****2.�ռ�*****" << endl << endl;
		cout << "*****************" << endl << endl;
		cout << "��ѡ��";
		cin >> a;
		switch (a)
		{
		case 0:exit(0);
			break;
		case 1:
			system("cls");
			PostSign(); break;
		case 2:
			system("cls");
			ReceSign(); break;
		default:cout << "*������󣬵ȴ�����ѡ��*" << endl;
			Sleep(1000);
			system("cls");
			break;
		}
		if(a==0)
			break;
	}
	
	return 0;
}

int PostSign() {
	int id, i;
	int num;
	string password;
	while (1)
	{
		cout << "*****���Ա��¼����*****" << endl << endl;
		cout << "*****0.�˳�*************" << endl << endl;
		cout << "*****1.�����˺�����*****" << endl << endl;
		cout << "************************" << endl << endl;
		cout << "�������:";
		cin >> num;
		switch (num) {
		case 0:
			system("cls");
			return 0;
			break;
		case 1:
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
			break;
		}
		if (num == 1)
			break;
	}
	for (i = 0; i < 100; i++) {
		if (postman[i] != NULL || id == postman[i]->getPostId()) {
			if (password == postman[i]->getPassWord()) {
				cout << "*��¼�ɹ�*" << endl;
				Sleep(1000);
				system("cls");
				Work();
				break;
			}
			else {
				cout << "*�������,���µ�¼*" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
		}
	}
	if (postman[i]==NULL||i==100) {
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
	return 0;
}

int Work() {
	int choice;
	while (1)
	{
		system("cls");
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
		case 0:
			return 0; break;
		case 1:
			Put(); break;
		case 2:
			system("cls");
			checkBox();
			system("pause"); break;
		case 3:
			system("cls"); 
			checkGoods();
			system("pause"); break;
		case 4:
			system("cls");
			checkOvertime();
			system("pause");
			break;
		default:cout << "������󣬵ȴ���������" << endl;
			Sleep(1000);
			break;
		}
		if (choice == 0)
			break;
	}
	return 0;
}