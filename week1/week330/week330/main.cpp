#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> v;
	int n, m;
	cout << "�����������ĸ���: ";
	cin >> n;
	cout << "��������������: ";
	for (int i = 0; i < n; i++){
		cin >> m;
		v.push_back(m);
	}
	vector<int>::iterator s;
	vector<int>::iterator e;
	s = v.begin(); e = v.end();
	sort(s, e);				//�㷨��Щ������������
	for (s = v.begin(); s != v.end(); s++){
		cout << (*s) << " ";
	}
	cout << "\n";
	cout << "������ҵ���: \n";
	cin >> m;
	vector<int>::iterator r;
	s = v.begin();
	r = find(s, e, m);		//���ص�����
	if (r == e)
		cout << "û��\n";
	else
		cout << "���� " << (*r) << endl;
	return 0;
}