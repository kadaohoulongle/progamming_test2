#pragma once
#include<iostream>
#include <time.h>
using namespace std;
class Goods
{
private:
	string pId;//�ļ���clintid
	string rId;//�ռ���clintid
	int station;//״̬ 0�������� 1���ڹ��� 2����ȡ��
	long long putTime;//����ʱ�� ,0:δ����  ��0����1970/1/1��ʼ������
	long long checkTime;//ȡ��ʱ��
	long long goodsId;

public:
	Goods(string a = "", string b = "", int c = 0, long long d = -1);

	void setpId(string str);
	void setrId(string str);
	void setStation(int s);
	void setPuttime();
	void setChecktime();
	void setGoodsId(long long a);

	string getpId()const;
	string getrId()const;
	int getStation()const;
	long long getPuttime()const;
	long long getChecktime()const;
	long long getGoodsId()const;

	void putGoods()
	{
		setPuttime();
		setStation(1);
	}
	void checkGoods()
	{
		setChecktime();
		setStation(2);
	}
};