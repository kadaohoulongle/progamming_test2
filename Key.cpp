#include "Key.h"
#include "Box.h"

Keys::Keys()
{
	head = new Keycell();
}

void Keys::insertKey(keytype k)
{
	k->next = head->next;
	head->next = k;
}

Keycell Keys::findKey(string kkey)
{
	keytype p = head->next;
	keytype q = head;
	while (p != NULL)
	{
		if (p->getKey() == kkey)
		{
			q->next = p->next;
			cout << "���Ϊ" << p->getGoodsId() 
				<< "�Ŀ�ݣ���" << p->getBoxId() 
				<< "�ſ�ݹ񣬵�" << p->index / Box::Boxw + 1 
				<< "�е�" << p->index % Box::Boxh + 1 
				<< "��" << endl;
			Keycell ret = *p;
			delete p;
			keyMap[kkey] = 0;
			return ret;
		}
		q = p;
		p = p->next;
	}
	return Keycell();//������󣬲���ʧ�� 
}

void Keys::printKeys() const
{
	keytype p = head->next;
	while (p != NULL)
	{
		cout << p->getKey() << " ";
		p = p->next;
	}
}

void Keys::findGoods(long long goodsId) const
{
	keytype p = head->next;
	while (p != NULL)
	{
		if (p->getGoodsId() == goodsId)
		{
			cout << "���Ϊ" << p->getGoodsId()
				<< "�Ŀ�ݣ���" << p->getBoxId()
				<< "�ſ�ݹ񣬵�" << p->index / Box::Boxw + 1
				<< "�е�" << p->index % Box::Boxh + 1
				<< "��" << endl;
			return;
		}
		p = p->next;
	}
}
