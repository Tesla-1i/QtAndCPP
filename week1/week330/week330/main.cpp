#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> v;
	int n, m;
	cout << "请输入整数的个数: ";
	cin >> n;
	cout << "请依次输入整数: ";
	for (int i = 0; i < n; i++){
		cin >> m;
		v.push_back(m);
	}
	vector<int>::iterator s;
	vector<int>::iterator e;
	s = v.begin(); e = v.end();
	sort(s, e);				//算法有些不局限于容器
	for (s = v.begin(); s != v.end(); s++){
		cout << (*s) << " ";
	}
	cout << "\n";
	cout << "输入查找的数: \n";
	cin >> m;
	vector<int>::iterator r;
	s = v.begin();
	r = find(s, e, m);		//返回迭代器
	if (r == e)
		cout << "没有\n";
	else
		cout << "存在 " << (*r) << endl;
	return 0;
}