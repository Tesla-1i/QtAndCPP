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
	LinkNode* hebing1(LinkNode* pHead1, LinkNode* pHead2);
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
		if (!pHead){		//头结点，非零为一
			pHead = pTail = pTemp;
		}
		else{
			//新增结点在后面
			pTail->next = pTemp;	//当前节点的指针域指向下一个结点
			pTail = pTemp;			//尾指针指向最后结点
			//新增结点在最前面
			//pTemp->next = pHead;	//新节点的指针域指向首结点
			//pHead = pTemp;		//头指针指向新的首结点
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

LinkNode* Link::hebing1(LinkNode* pHead1, LinkNode *pHead2){
	LinkNode *pTemp1 = pHead1, *pTemp2 = pHead2;
	while ((pTemp2->next) != 0){		//bug所在，pTemp2 != 0,出错
		if ((pTemp2->data) >= (pTemp1->data) && (pTemp2->data) <= (pTemp1->next->data)){
			LinkNode* temp = pTemp2->next;
			pTemp2->next = pTemp1->next;
			pTemp1->next = pTemp2;
			pTemp1 = pTemp1->next->next;
			pTemp2 = temp;
		}
		else
			pTemp2 = pTemp2->next;
	}
	pTemp1->next = pTemp2;	//bug所在。否则没有最后一个。
	return pHead1;
}

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
	cout << "合并成一个有序链表\n";
	LinkNode *pHead11, *pHead21;
	cout << "第一个有序链表\n";
	pHead11 = Link1.create();
	cout << "第二个有序链表\n";	
	pHead21 = Link1.create();
	LinkNode* pResualt2;
	pResualt2 = Link1.hebing1(pHead11, pHead21);
	Link1.list(pResualt2);
	return 0;
}

/*链表习题
所有习题要求基于带头结点的链表完成，并采用类来实现; 每个操作定义函数实现

基本题目
1. 建立链表（数据域只有一个整型）
（1） 每次新增结点放在最前面
（2） 每次新增结点放在最后面
（3） 每次新增结点有序插入

2. 遍历链表
输出链表节点数据，核心语句 p = p->next

3. 查找结点
（1）按照编号查找，即查找第几个节点
（2）按照数据查找

4. 删除结点
（1）按照编号删除，即删除第几个
（2）按照数据查找并删除

5.  对有序链表合并
（1）合并后生成新链表
（2）合并后不生成新的链表（a 、b合并结果在a中）*/






