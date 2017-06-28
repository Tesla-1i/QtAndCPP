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
	cout << "��������(data<0����)\n";
	cin >> data;
	while (data > 0){
		pTemp = new LinkNode;
		pTemp->data = data;
		pTemp->next = 0;
		if (!pHead){		//ͷ��㣬����Ϊһ
			pHead = pTail = pTemp;
		}
		else{
			//��������ں���
			pTail->next = pTemp;	//��ǰ�ڵ��ָ����ָ����һ�����
			pTail = pTemp;			//βָ��ָ�������
			//�����������ǰ��
			//pTemp->next = pHead;	//�½ڵ��ָ����ָ���׽��
			//pHead = pTemp;		//ͷָ��ָ���µ��׽��
		}
		//cout << "��������\n";
		cin >> data;
	}
	return pHead;
}

void Link::list(LinkNode* pHead){
	while (pHead){
		cout << pHead->data << " ";
		pHead = pHead->next;	//�ؼ�
	}
	cout << "\n";
}

LinkNode* Link:: search(LinkNode* pHead){
	int m;
	cout << "�������ݲ�������1�����ձ�Ų�������2\n";
	cin >> m;
	switch (m)
	{
	case 1:{
			   int data;
			   cout << "��������ҵ�����\n";
			   cin >> data;
			   while (pHead){
				   if (pHead->data == data)
					   break;
				   pHead = pHead->next;
			   }
			   break;
	}case 2:{
			   int n;
			   cout << "��������ҵı��(��һ�����Ϊ1)\n";
			   cin >> n;
			   for (int i = 0; i < n - 1; i++){
				   pHead = pHead->next;
				   if (!pHead)
					   break;	//�Ѿ�������ˣ�������
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
	cout << "�Ȳ��Һ�ɾ��\n";
	p = search(pHead);
	if (p)
		cout << "���ݴ���\n";
	else {
		cout << "���ݲ�����\n";
		return pHead;
	}
	q = pHead;
	if (p == pHead){	//ɾ����һ�����
		pHead = pHead->next;
		delete p;
		return pHead;
	}
	while ((q != NULL) && (q->next) != p)
		q = q->next;
	//����ƶ�q��ֱ��q��pǰһ��.
	q->next = p->next;
	delete p;
	return pHead;
}
LinkNode* Link::hebing(LinkNode* pHead1, LinkNode*pHead2){
	LinkNode *head = new LinkNode;	//�½�һ�����
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
	//����һ������ʣ�����һ�����
	if (pHead1 != NULL)	//pHead1ָ�����һ����pHead2ָ��NUll��
		temp->next = pHead1;
	if (pHead2 != NULL)	//��������bug,д��pHead2->next;
		temp->next = pHead2;
	return head->next;	//����head����ԭ�ȵĵ�һ�����.

	//�ο�ttp://wiki.jikexueyuan.com/project/for-offer/question-senenteen.html
}

LinkNode* Link::hebing1(LinkNode* pHead1, LinkNode *pHead2){
	LinkNode *pTemp1 = pHead1, *pTemp2 = pHead2;
	while ((pTemp2->next) != 0){		//bug���ڣ�pTemp2 != 0,����
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
	pTemp1->next = pTemp2;	//bug���ڡ�����û�����һ����
	return pHead1;
}

int main(){
	Link Link1;
	cout << "������һ������\n";
	LinkNode *pHead, *pResualt = 0;
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
	cout << "������\n";
	Link1.list(pHead);
	cout << "�ϲ�������������(����������)\n";
	LinkNode *pHead1, *pHead2;
	cout << "��һ����������\n";
	pHead1 = Link1.create();
	cout << "�ڶ�����������\n";
	pHead2 = Link1.create();
	LinkNode* pResualt1;
	pResualt1 = Link1.hebing(pHead1, pHead2);
	Link1.list(pResualt1);
	cout << "�ϲ���һ����������\n";
	LinkNode *pHead11, *pHead21;
	cout << "��һ����������\n";
	pHead11 = Link1.create();
	cout << "�ڶ�����������\n";	
	pHead21 = Link1.create();
	LinkNode* pResualt2;
	pResualt2 = Link1.hebing1(pHead11, pHead21);
	Link1.list(pResualt2);
	return 0;
}

/*����ϰ��
����ϰ��Ҫ����ڴ�ͷ����������ɣ�����������ʵ��; ÿ���������庯��ʵ��

������Ŀ
1. ��������������ֻ��һ�����ͣ�
��1�� ÿ��������������ǰ��
��2�� ÿ�����������������
��3�� ÿ����������������

2. ��������
�������ڵ����ݣ�������� p = p->next

3. ���ҽ��
��1�����ձ�Ų��ң������ҵڼ����ڵ�
��2���������ݲ���

4. ɾ�����
��1�����ձ��ɾ������ɾ���ڼ���
��2���������ݲ��Ҳ�ɾ��

5.  ����������ϲ�
��1���ϲ�������������
��2���ϲ��������µ�����a ��b�ϲ������a�У�*/






