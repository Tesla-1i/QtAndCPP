#include<iostream>
#include<list>
#include<algorithm>
#include<utility>

using namespace std;

template<class T>
bool test(list<T> l){
	list<T> l1(l);
	//l1 = l;
	l1.reverse();		//颠倒链表
	return (l1 == l);
}

int main(){
	//const list<int> l;
	cout << "输入五个整数\n";
	int a[5];
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	list<int> l(a, a + 5);
	bool b = test(l);
	if (b)
		cout << "true" << endl;
	else
	{
		cout << "false" << endl;
	}
	return 0;
}