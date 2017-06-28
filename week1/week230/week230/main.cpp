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
	//LinkNode* hebing1(LinkNode* pHead1, LinkNode* pHead2);
};

LinkNode* Link::create(){
	LinkNode *pHead=0, *pTemp, *pTail=0;
	int data;
	cout << "输入数据(data<0结束)\n";
	cin >> data;
	while (data > 0){
		pTemp = new LinkNode;
		pTemp->data = data;
		pTemp->next = 0;
		if (!pHead){
			pHead = pTail = pTemp;
		}
		else{
			//新增结点在后面
			pTail->next = pTemp;
			pTail = pTemp;
			//新增结点在最前面
			//pTemp->next = pHead;
			//pHead = pTemp;
		}
		//cout << "输入数据\n";
		cin >> data;
	}
	return pHead;
}

void Link::list(LinkNode* pHead){
	while (pHead){
		cout << pHead->data << " ";
		pHead = pHead->next;	//关键
	}
	cout << "\n";
}

LinkNode* Link:: search(LinkNode* pHead){
	int m;
	cout << "按照数据查找输入1，按照编号查找输入2\n";
	cin >> m;
	switch (m)
	{
	case 1:{
			   int data;
			   cout << "请输入查找的数据\n";
			   cin >> data;
			   while (pHead){
				   if (pHead->data == data)
					   break;
				   pHead = pHead->next;
			   }
			   break;
	}case 2:{
			   int n;
			   cout << "请输入查找的编号(第一个编号为1)\n";
			   cin >> n;
			   for (int i = 0; i < n - 1; i++){
				   pHead = pHead->next;
				   if (!pHead)
					   break;	//已经到最后了，则跳出
			   }
			   break;
	}
	default:
		break;
	}
	return pHead;
}
LinkNode*  Link::erase(LinkNode* pHead){
	LinkNode *p, *q;
	cout << "先查找后删除\n";
	p = search(pHead);
	if (p)
		cout << "数据存在\n";
	else {
		cout << "数据不存在\n";
		return pHead;
	}
	q = pHead;
	if (p == pHead){	//删除第一个结点
		pHead = pHead->next;
		delete p;
		return pHead;
	}
	while ((q != NULL) && (q->next) != p)
		q = q->next;
	//向后移动q，直到q在p前一个.
	q->next = p->next;
	delete p;
	return pHead;
}
LinkNode* Link::hebing(LinkNode* pHead1, LinkNode*pHead2){
	LinkNode *head = new LinkNode;	//新建一个结点
	LinkNode *temp = head;
	while ((pHead1 != NULL) && (pHead2 != NULL)){
		if ((pHead1->data) < (pHead2->data)){
			temp->next = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			temp->next = pHead2;
			pHead2 = pHead2->next;
		}
		temp = temp->next;
	}
	//其中一个链表剩下最后一个结点
	if (pHead1 != NULL)	//pHead1指向最后一个，pHead2指向NUll。
		temp->next = pHead1;
	if (pHead2 != NULL)	//曾经出现bug,写成pHead2->next;
		temp->next = pHead2;
	return head->next;	//不是head，是原先的第一个结点.

	//参考ttp://wiki.jikexueyuan.com/project/for-offer/question-senenteen.html
}

/*LinkNode* Link::hebing1(LinkNode* pHead1, LinkNode *pHead2){

}*/

int main(){
	Link Link1;
	cout << "创建第一个链表\n";
	LinkNode *pHead, *pResualt = 0;
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
	cout << "新链表\n";
	Link1.list(pHead);
	cout << "合并两个有序链表(生成新链表)\n";
	LinkNode *pHead1, *pHead2;
	cout << "第一个有序链表\n";
	pHead1 = Link1.create();
	cout << "第二个有序链表\n";
	pHead2 = Link1.create();
	LinkNode* pResualt1;
	pResualt1 = Link1.hebing(pHead1, pHead2);
	Link1.list(pResualt1);
	/*cout << "合并成一个有序链表\n";
	LinkNode *pHead11, *pHead21;
	cout << "第一个有序链表\n";
	pHead11 = Link1.create();
	cout << "第二个有序链表\n";	
	pHead21 = Link1.create();
	LinkNode* pResualt2;
	pResualt2 = Link1.hebing1(pHead11, pHead21);
	Link1.list(pResualt2);*/
	return 0;
}
