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
	cout << "输入数据(data>0)\n";
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
		cout << "输入数据\n";
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
	cout << "创建第一个链表\n";
	LinkNode *pHead, *pResualt;
	pHead = Link1.create();
	cout << "遍历链表\n";
	//cout << "查找：\n";
	Link1.list(pHead);
	cout << "查找\n";
	pResualt = Link1.search(pHead);
	if (pResualt)
		cout << "查找的数据 " << pResualt->data << endl;
	else
		cout << "not found!\n";
	cout << "删除\n";
	pHead = Link1.erase(pHead);
	return 0;
}
