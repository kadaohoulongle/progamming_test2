#define _CRT_SECURE_NO_WARNINGS
#include"Sign.h"

int recordMenu = 1;
int recordPostsign = 1;
int recordWork = 1;
//��ݵ�ѡ�񣺿��Ա���ռ���
int Menu() {
	while (recordMenu) {
		cout << "*****���˵�******" << endl << endl;
		cout << "****0.�˳�*******" << endl << endl;
		cout << "****1.���Ա*****" << endl << endl;
		cout << "****2.�ռ�*******" << endl << endl;
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
			PostSign();
			recordMenu = 1;
			break;
		case 2:Sleep(1000);
			system("cls");
			ReceSign();
			recordMenu = 1;
			break;
		default:cout << "*������󣬵ȴ�����ѡ��*" << endl;
			Sleep(1000);
			system("cls");
			recordMenu = 1;
			break;
		}
	}
	return 0;
}

int PostSign() {
	recordPostsign = 1;
	int id = -1, i = -1, record = 0;
	int num = -1;
	string password = "";
	while (recordPostsign)
	{
		cout << "*****���Ա��¼����*****" << endl << endl;
		cout << "*****0.�˳�*************" << endl << endl;
		cout << "*****1.�����˺�����*****" << endl << endl;
		cout << "************************" << endl << endl;
		cout << "�������:";
		cin >> num;
		switch (num) {
		case 0:Sleep(1000);
			system("cls");
			recordPostsign = 0;
			recordMenu = 1;
			break;
		case 1:Sleep(1000);
			system("cls");
			cout << "***�����˺��������***" << endl << endl;
			cout << "******�������˺�******" << endl;
			cin >> id;
			cout << endl;
			cout << "******����������******" << endl;
			cin >> password;
			cout << endl;
			recordPostsign = 1;
			break;
		default:cout << "*�������,�ȴ���������ѡ��*" << endl;
			Sleep(1000);
			system("cls");
			recordPostsign = 1;
			break;
		}
		if (num == 1) {
			for (i = 0; i < 100; i++) {
				if (postman[i] != NULL && id == postman[i]->getPostId()) {
					if (password == postman[i]->getPassWord()) {
						cout << "*��¼�ɹ�*" << endl;
						record = 1;
						recordPostsign = 0;
						Sleep(1000);
						system("cls");
						break;
					}
					else {
						cout << "*�������,���µ�¼*" << endl;
						Sleep(1000);
						system("cls");
						break;
					}
				}
				if (postman[i] == NULL) {
					cout << "*�˺Ų�����,��ȴ���������ѡ��*" << endl;
					recordPostsign = 1;
					Sleep(1000);
					system("cls");
					break;
				}
			}
		}
		if (num == 1 && record)
			Work();
	}

	return 0;
}

int ReceSign() {
	Check();
	cout << "*�ȴ��������˵�*" << endl;
	Sleep(3000);
	system("cls");
	recordMenu = 1;
	return 0;
}

int Work() {
	int choice = -1;
	recordWork = 1;
	while (recordWork) {
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
			recordWork = 0;
			recordPostsign = 1;
			break;
		case 1:Sleep(1000);
			system("cls");
			Put();
			Sleep(1000);
			recordWork = 1;
			Sleep(1000);
			system("cls");
			break;
		case 2:Sleep(1000);
			system("cls");
			checkBox();
			Sleep(1000);
			recordWork = 1;
			Sleep(1000);
			system("cls");
			break;
		case 3:Sleep(1000);
			system("cls");
			checkGoods();
			Sleep(1000);
			recordWork = 1;
			Sleep(1000);
			system("cls");
			break;
		case 4:Sleep(1000);
			system("cls");
			checkOvertime();
			Sleep(1000);
			recordWork = 1;
			Sleep(1000);
			system("cls");
			break;
		default:cout << "������󣬵ȴ���������" << endl;
			Sleep(1000);
			system("cls");
			recordWork = 1;
			break;
		}
	}
	return 0;
}