#pragma once
#include<iostream>
#include"Keycell.h"
using namespace std;
class Keys
{
	typedef Keycell* keytype;
	typedef Keycell* Head;
private:
	Head head;

public:
	Keys();

	void insertKey(keytype k);//�ڱ��в���һ��key 

	Keycell findKey(string kkey);//ͨ��keyֵ���� ,�ɹ���ɾ�� 

	void printKeys()const;//������ 

	void findGoods(long long goodsId)const;//����idѰ�ҿ��

};