#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

class Order{
private:
	int goods_id;
	int goods_number;
public:
	Order(int gid, int gnum);
	void print();
	bool operator ==(int gid);
};

Order::Order(int gid, int gnum){
	goods_id = gid;
	goods_number = gnum;
}

void Order::print(){
	cout << "id: " << goods_id << " number: " << goods_number << endl;
}
bool Order::operator==(int gid){
	return (goods_id == gid);
}

class Cart{
private:
	list<Order*> l_goods;		//������Order���͵�ָ��
public:
	void add(Order* or);
	void print();
	bool del(int gid);
};

void Cart::add(Order* or){
	l_goods.push_back(or);
}
 
void Cart::print(){
	//cout << "ppp ";
	list<Order*>::iterator it;
	for (it = l_goods.begin(); it != l_goods.end(); it++){
		//Order *or = (*it);
		//cout << "print ";
		(*it)->print();			//ָ����ó�Ա������->,���ǡ�
	}
}

bool Cart::del(int gid){
	list<Order*>::iterator it;
	list<Order*>::iterator pos;
	bool b = false;
	for (it = l_goods.begin(); it != l_goods.end(); it++){
		if ((*it)->operator==(gid)){
			pos = it;
			b = true;
			//l_goods.erase(pos);
			//return true;
		}
	}
	if (b){
		l_goods.erase(pos);
		return true;
	}
	return false;
}

int main(){
	Cart c;
	int n, i;
	int gid, gnum;
	cout << "��Ҫ����������Ʒ " << endl;
	cin >> n;
	cout << "����add" << endl;
	for (i = 0; i < n; i++){
		cout << "�����" << i + 1 << "������" << endl;
		cin >> gid >> gnum;
		c.add(new Order(gid, gnum));		//bug���ڣ���Ȼû��д��仰
	}
	cout << "��Ķ�����Ϣ" << endl;
	c.print();
	cout << "����del,����Ҫɾ���ı��\n";
	cin >> gid;
	c.del(gid);
	cout << "��Ķ�����Ϣ" << endl;
	c.print();
}









//ttp://bbs.bccn.net/thread-416541-1-1.html