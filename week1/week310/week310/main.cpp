#include<iostream>
#include<vector>
#include<algorithm>
#include<xutility>
#include<utility>
using namespace std;

template<class T>
bool test(const vector<T> v){
	int n = v.size();
	for (int i = 0; i < n / 2; i++){	//vector 重载了[];
		if (v[i] != v[n - i - 1])		//比较范围，注意;
			return false;
	}
	return true;
	
}

int main(){
	vector<int> v;
	cout << "输入五个整数\n";
	int j;
	for (int i = 0; i < 5; i++){
		cin >> j;
		v.push_back(j);
	}
	bool b = test(v);
	if (b)
		cout << "true" << endl;
	else cout << "flase" << endl;
	return 0;
}

//ttps://zhidao.baidu.com/question/564394393.html