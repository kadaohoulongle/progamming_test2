#pragma once
#include<iostream>
using namespace std;
class Person//���࣬�����˵Ļ�����Ϣ 
{
private:
	string id;//���֤��
	string tel;//�绰 
	string name;//���� 
public:
	string getId()const;
	string getTel()const;
	string getName()const;
	void setId(string str);
	void setTel(string str);
	void setName(string str);
	Person(string a = "", string b = "", string c = "");
};