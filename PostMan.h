#pragma once
#include"Person.h"
class PostMan :public Person//�ʵ�Ա��
{
private:
	int postId;//����
	string position;//ְλ
	string passWord;//����
public:

	int getPostId()const;
	string getPosition()const;
	string getPassWord()const;
	void setPassWord(string str);
	void setPosition(string str);
	void setPostId(int pId);
	PostMan(string a = "", string b = "", string c = "", int d = -1, string e = "", string f = "");
};