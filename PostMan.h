#pragma once
#include"Person.h"
class PostMan :public Person//�ʵ�Ա�� 
{
private:
	int postId;//���� 
	string position;//ְλ

public:

	int getPostId()const;
	string getPosition()const;
	void setPosition(string str);
	void setPostId(int pId);
	PostMan(string a = "", string b = "", string c = "", int d = -1, string e = "");
};