#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	map<string, int> m;
	m.insert(make_pair(string("zero"), 0));		//make_pair(),绑定两个对象为一个
	m.insert(make_pair(string("one"), 1));
	m.insert(make_pair(string("two"), 2));
	m.insert(make_pair(string("three"), 3));
	m.insert(make_pair(string("four"), 4));
	m.insert(make_pair(string("five"), 5));
	m.insert(make_pair(string("six"), 6));
	m.insert(make_pair(string("seven"), 7));
	m.insert(make_pair(string("eight"), 8));
	m.insert(make_pair(string("nine"), 9));
	m.insert(make_pair(string("ten"), 10));
	string s;
	cout << "请输入英文单词： ";
	cin >> s;
	if (m.find(s) != m.end())
		cout << m[s] << endl;			//set重载了[],由key返回value.
	else
		cout << "error,没有" << endl;
	return 0;
}