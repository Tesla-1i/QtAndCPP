#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

class LinkNode{
public:
	int data;
	LinkNode* next;
	LinkNode(int d=0, LinkNode* n = 0){
		data = d;
		next = n;
	}
};

class Link{
public:
	LinkNode* create();
	void list(LinkNode* pHead);
	LinkNode* search(LinkNode* pHead);
	LinkNode* erase(LinkNode* pHead);
	LinkNode* hebing(LinkNode* pHead1, LinkNode*pHead2);
};

LinkNode* Link::create(){
	LinkNode *pHead=0, *pTemp, *pTail=0;
	int data;
	cout << "��������(data>0)\n";
	cin >> data;
	while (data > 0){
		pTemp = new LinkNode;
		pTemp->data = data;
		pTemp->next = 0;
		if (!pHead){
			pHead = pTail = pTemp;
		}
		else{
			pTail->next = pTemp;
			pTail = pTemp;
		}
		cout << "��������\n";
		cin >> data;
	}
	return pHead;
}

void Link::list(LinkNode* pHead){
	while (pHead){
		cout << pHead->data << " ";
		pHead = pHead->next;
	}
	cout << "\n";
}

LinkNode* Link:: search(LinkNode* pHead){
	return pHead;
}
LinkNode* Link::erase(LinkNode* pHead){
	return pHead;
}
LinkNode* Link::hebing(LinkNode* pHead1, LinkNode*pHead2){
	return pHead1;
}

int main(){
	Link Link1;
	cout << "������һ������\n";
	LinkNode *pHead, *pResualt;
	pHead = Link1.create();
	cout << "��������\n";
	//cout << "���ң�\n";
	Link1.list(pHead);
	cout << "����\n";
	pResualt = Link1.search(pHead);
	if (pResualt)
		cout << "���ҵ����� " << pResualt->data << endl;
	else
		cout << "not found!\n";
	cout << "ɾ��\n";
	pHead = Link1.erase(pHead);
	return 0;
}
