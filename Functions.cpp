#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Functions.h"
using namespace std;
PostMan* postman[100];
Client* client[100];
Goods* goods[100];
Box* box[100];
Keys keys;

void getPostMan()
{
	string a, b, c, e;
	int d;
	fstream fio("D:\\postman.txt", ios::in | ios::out);
	if (fio.is_open())
	{
		for (int i = 0; i < 100; i++)
		{
			fio >> a >> b >> c >> d >> e;
			postman[i] = new PostMan(a, b, c, d, e);
			if (fio.eof())
				break;
		}
		fio.close();
	}
	else
		cout << "�ļ���ʧ��" << endl;
}

void getClient()
{
	string a, b, c, d;
	int e;
	fstream fio("D:\\client.txt", ios::in | ios::out);
	if (fio.is_open())
	{
		for (int i = 0; i < 100; i++)
		{
			fio >> a >> b >> c >> d >> e;
			client[i] = new Client(a, b, c, d, e);
			if (fio.eof())
				break;
		}
		fio.close();
	}
	else
		cout << "�ļ���ʧ��" << endl;
}

void getGoods()
{
	string a, b;
	int c,d;
	fstream fio("D:\\client.txt", ios::in | ios::out);
	if (fio.is_open())
	{
		for (int i = 0; i < 100; i++)
		{
			fio >> a >> b >> c >> d;
			goods[i] = new Goods(a, b, c, d);
			if (fio.eof())
				break;
		}
		fio.close();
	}
	else
		cout << "�ļ���ʧ��" << endl;
}
void initial()
{
	getPostMan();
	getClient();
	getGoods();
	box[0] = new Box(1, 2);
	box[1] = new Box(2, 2);

	keys.insertKey(new Keycell("111111", 3, 0, 0));
	keys.insertKey(new Keycell("123456", 2, 1, 0));
	goods[3]->setPuttime();
	goods[3]->putGoods();
	box[0]->putBox(0);
}

void Put()
{
	//�����û��������룬��
	int boxId;
	int freeIndex;
	long long goodsId;
	cout << "���뵱ǰ��ݹ���" << endl;
	cin >> boxId;
	if (boxId > 1 || boxId < 0)
	{
		cout << "�������" << endl;
		return;
	}
	freeIndex = box[boxId]->getFreeBox();
	if (freeIndex == -1)
	{
		cout << "�˹��������뻻һ��" << endl;
		return;
	}
	box[boxId]->printBox(freeIndex);
	cout << "������Ҫ����Ŀ�ݱ��" << endl;
	cin >> goodsId;
	if (goodsId < 0 || goodsId>3)
	{
		cout << "�����ڴ˿�ݣ�����������" << endl;
		return;
	}
	if (goods[goodsId]->getStation() != 0)
	{
		cout << "�˿���ѷ������ȡ��������������" << endl;
		return;
	}
	goods[goodsId]->putGoods();
	box[boxId]->putBox(freeIndex);
	Keycell* temp = new Keycell("", goodsId, boxId, freeIndex);
	temp->setRandomKey();
	keys.insertKey(temp);
	cout << "�ѳɹ�����" << endl;
	temp->sendMessage();

	return;

}

void Check()
{

	string key;
	Keycell temp;
	cout << "����������" << endl;
	cin >> key;
	temp = keys.findKey(key);
	if (temp.getKey() == "")
	{
		cout << "������󣬲����ڴ����룬�����Ƿ��������" << endl;
		return;
	}
	box[temp.getBoxId()]->checkBox(temp.index);
	goods[temp.getGoodsId()]->checkGoods();
	cout << "ȡ���ɹ�" << endl;

}

void checkBox()
{
	int boxId;
	cout << "���뵱ǰ��ݹ���" << endl;
	cin >> boxId;
	if (boxId > 1 || boxId < 0)
	{
		cout << "�������" << endl;
		return;
	}
	cout << "��ݹ�ʹ���������" << endl;
	box[boxId]->printBoxStation();
	return;
}

void checkGoods()
{
	int goodsId;
	cout << "�������ݱ��" << endl;
	cin >> goodsId;
	if (goodsId < 0 || goodsId>3)
	{
		cout << "�����ڴ˿�ݣ�����������" << endl;
		return;
	}
	if (goods[goodsId]->getStation() == 2)
	{
		time_t seconds;

		seconds = time(NULL);
		long long a = seconds;
		cout << "���Ϊ" << goodsId
			<< "�Ŀ���Ѿ���" << a - goods[goodsId]->getChecktime()
			<< "��ǰ��ȡ��" << endl;
		return;
	}

	else if (goods[goodsId]->getStation() == 1)
	{
		keys.findGoods(goodsId);
		return;
	}

	else
	{
		cout << "�˿�ݲ�δ�����ݹ�" << endl;
		return;
	}
}

bool checkOvertime()
{
	time_t seconds;
	seconds = time(NULL);
	long long a = seconds;
	for (long long i = 0; i < 4; i++)
		if (goods[i]->getStation() == 1 && a - goods[i]->getPuttime() >= 10)//20s������ 
		{
			keys.findGoods(i);
			return true;
		}
	return false;
}
