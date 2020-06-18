#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Functions.h"
using namespace std;
PostMan* postman[100];
Client* client[100];
Goods* goods[100];
Box* box[100];
Keys keys;
void initial()
{
	FILE* fp;
	if (fp = fopen("D:\\test.txt", "w"))
	{
		cout << "���ļ��ɹ�" << endl;
		fputs("hello", fp);
		fclose(fp);
	}
	else
		cout << "���ļ�ʧ��" << endl;
	postman[0] = new PostMan("123451", "110", "PostmanA", 0, "worker");
	postman[1] = new PostMan("123452", "111", "PostmanB", 1, "manager");


	client[0] = new Client("123453", "119", "ClientC", "������԰", 0);
	client[1] = new Client("123454", "120", "ClientD", "������ʳ��", 1);
	client[2] = new Client("123454", "121", "ClientE", "�Ͼ���ҵ��ѧ", 2);

	goods[0] = new Goods("3", "4", 0, 0);
	goods[1] = new Goods("4", "5", 0, 1);
	goods[2] = new Goods("5", "3", 1, 2);
	goods[3] = new Goods("4", "3", 2, 3);

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
