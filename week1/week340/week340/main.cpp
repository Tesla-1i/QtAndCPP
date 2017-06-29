#include<iostream>
#include<set>
#include<iterator>		//一定要有,bug所在
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
				//s2.erase(it2);		//不能删除
			}
		}
	}
	return s3;
}

int main(){
	int i;
	cout << "第一个集合的个数：";
	cin >> i;
	int *a = new int[i];
	cout << "输入元素： ";
	for (int k = 0; k < i; k++){
		cin >> a[k];
	}
	set<int> s1(a, a + i);
	cout << "第二个集合的个数： ";
	cin >> i;
	cout << "输入元素： ";
	int *b = new int[i];
	for (int k = 0; k < i; k++){
		cin >> b[k];
	}



	set<int> s2(b, b + i);
	set<int> si;
	set<int>::iterator site;
	si = intersection(s1, s2);
	//stl中的模板-交集
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
set里面有set_intersection（取集合交集）、set_union（取集合并集）、set_difference（取集合差集）
、set_symmetric_difference（取集合对称差集）等函数。其中，关于函数的五个参数问题做一下小结：

1、这几个函数的前四个参数一样，只有第五个参数有多重版本。

2、EX1：set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(C1, C1.begin()));
前四个参数依次是第一的集合的头尾，第二个集合的头尾。第五个参数的意思是将集合A、B取合集后的结果存入集合C中。

EX2：set_union(A.begin(), A.end(), B.begin(), B.end(), ostream_iterator<int>(cout, " “));
这里的第五个参数的意思是将A、B取合集后的结果直接输出，（cout," "）双引号里面是输出你想用来间隔集合元素的符号或是空格。
*/