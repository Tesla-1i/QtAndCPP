#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;
class Dictionary{
private:
	map<string, string> dict;
public:
	void displayAll();
	void delItem(string word);
	void addItem(string word, string explanation);
	string lookup(string word);
};

void Dictionary::displayAll(){
	map<string, string>::iterator it;
	for (it = dict.begin(); it != dict.end(); it++)
		cout << it->first << " : " << it->second << endl;		//关键
}

void Dictionary::delItem(string word){
	dict.erase(word);
}

void Dictionary::addItem(string word, string explanation){
	dict.insert(make_pair(word, explanation));		//关键
}

string Dictionary::lookup(string word){
	if (dict.find(word) != dict.end())
		return dict[word];		//关键
	else
		return string("没有找到");
}

int main(){
	Dictionary dt;
	dt.addItem(string("one"), string("一，一个"));
	dt.addItem(string("two"), string("二，二个"));
	dt.addItem(string("China"), string("中国"));
	dt.displayAll();
	cout << endl;
	cout << (dt.lookup(string("China"))) << endl;
	cout << (dt.lookup(string("English"))) << endl;
	dt.delItem(string("one"));
	dt.displayAll();
	return 0;

	/*vector<int> v1;
	vector<int> v2;
	v1.push_back(5); v1.push_back(2);
	v2.push_back(1); v2.push_back(1);*/
	//cout << (v1 > v2) << endl;
	/*int i;
	vector<int> v1(5);
	cout << v1.end() - v1.begin() << endl;
	for (i = 0; i < v1.size(); i++)
		v1[i] = i;
	v1.at(4) = 100;
	for (i = 0; i < v1.size(); i++){
		cout << v1[i] << " ";
	}
	cout << endl;
	int a[5] = { 1, 2, 3, 4, 5 };
	vector<int> v2(a, a + 5);
	v2.insert(v2.begin() + 2, 13);
	for (i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
	
	vector<int> v;
	for (int k = 1; k < 5; k++){
		v.push_back(k);
	}
	vector<int>::iterator i;
	for (i = v.begin(); i != v.end(); i++){
		cout << (*i) << "\t";
	}
	cout << endl;
	vector<int>::reverse_iterator r;
	for (r = v.rbegin(); r != v.rend(); r++){
		cout << (*r) << "\t";
	}
	cout << endl;

	vector<int> ivec;
	for (vector<int>::size_type ix = 0; ix != 10; ix++){
		ivec.push_back(ix);
		cout << ivec[ix] << "\t";
	}
	cout << endl;
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); iter++){
		(*iter) *= 2;
		cout << (*iter) << "\t";

	}*/


	
}