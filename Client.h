#pragma once
#include"Person.h"
class Client :public Person//�ļ��˺��ռ����� 
{
private:
	string address;//��ַ
	int clintId;//�ͻ��ı�� 

public:
	void setAddress(string str);
	void setClintId(int cId);
	string getAddress()const;
	int getClintId()const;
	Client(string a, string b, string c, string d, int e);
};