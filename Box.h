#pragma once
#include<iostream>
using namespace std;
class Box
{
public:
	const static int Boxw = 3;//��� 
	const static int Boxh = 3;//��� 

private:
	bool box[Boxh * Boxw];
	//long long idbox[Boxh*Boxw];
	int boxId;//��ݹ��id 
	int postId;//������Ա��� 

public:
	Box(int id, int pId);
	int getpostId();
	void setpostId(int a);
	int getFreeBox()const;//Ѱ�ҿչ��� 

	void printBox(int index)const;//������ӵ��к���(xx��xx�пɷ���)

	void putBox(int index);//box[i]=1

	void checkBox(int index);//box[i]=0

	void printBoxStation();//��ѯ��ʹ�����




};