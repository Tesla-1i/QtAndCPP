#include<iostream>
#include<set>
#include<iterator>		//һ��Ҫ��,bug����
#include<algorithm>
#include<utility>
using namespace std;

set<int> intersection(set<int> s1, set<int> s2){
	set<int> s3;
	set<int>::iterator it1;
	set<int>::iterator it2;
	//it1 = s1.begin();
	//cout << *it1 << endl;
	for (it1 = s1.begin(); it1 != s1.end(); it1++){
		for (it2 = s2.begin(); it2 != s2.end(); it2++){
			if (*it1 == *it2){
				int i = *it2;
				s3.insert(i);
				//s1.erase(it1);
				//s2.erase(it2);		//����ɾ��
			}
		}
	}
	return s3;
}

int main(){
	int i;
	cout << "��һ�����ϵĸ�����";
	cin >> i;
	int *a = new int[i];
	cout << "����Ԫ�أ� ";
	for (int k = 0; k < i; k++){
		cin >> a[k];
	}
	set<int> s1(a, a + i);
	cout << "�ڶ������ϵĸ����� ";
	cin >> i;
	cout << "����Ԫ�أ� ";
	int *b = new int[i];
	for (int k = 0; k < i; k++){
		cin >> b[k];
	}



	set<int> s2(b, b + i);
	set<int> si;
	set<int>::iterator site;
	si = intersection(s1, s2);
	//stl�е�ģ��-����
	//set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(si, si.begin()));
	for (site = si.begin(); site != si.end(); site++){
		cout << (*site) << " ";
	}
	cout << endl;
	return 0;
}







/*
ttp://blog.csdn.net/zangker/article/details/22984803
ttp://blog.csdn.net/maverick1990/article/details/23194643
set������set_intersection��ȡ���Ͻ�������set_union��ȡ���ϲ�������set_difference��ȡ���ϲ��
��set_symmetric_difference��ȡ���϶ԳƲ���Ⱥ��������У����ں������������������һ��С�᣺

1���⼸��������ǰ�ĸ�����һ����ֻ�е���������ж��ذ汾��

2��EX1��set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(C1, C1.begin()));
ǰ�ĸ����������ǵ�һ�ļ��ϵ�ͷβ���ڶ������ϵ�ͷβ���������������˼�ǽ�����A��Bȡ�ϼ���Ľ�����뼯��C�С�

EX2��set_union(A.begin(), A.end(), B.begin(), B.end(), ostream_iterator<int>(cout, " ��));
����ĵ������������˼�ǽ�A��Bȡ�ϼ���Ľ��ֱ���������cout," "��˫����������������������������Ԫ�صķ��Ż��ǿո�
*/