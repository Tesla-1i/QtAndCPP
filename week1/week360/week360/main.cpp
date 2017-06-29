#include<iostream>
#include<map>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;

void main()
{

	cout << "请输入文章以.结尾" << endl;
	string s;
	map<string, int>p;
	do
	{
		cin >> s;
		p[s]++;		//?关键所在。

	} while (s != ".");
	for (map<string, int>::iterator iter = p.begin(); iter != p.end(); ++iter)
	{
		if ((iter->first) != ".")
			cout << iter->first << "   " << iter->second << endl;
	}
}


/*
给map容器添加元素，可使用 insert 成员实现；或者，先用下标操作符获取元素，然后给获取的元素赋值。
使用下标访问map：
map< string, int > word_count;
word_count["WB"] = 1;
1
2
1
2
将发生以下事情：
在 word_count 中查找键为 WB 的元素，没有找到。
将一个新的键－值对插入到 word_count 中。它的键是 const string 类型的对象， 保存 WB。 而它的值则采用值初始化， 这就意味着在本例中值为 0。
将这个新的键－值对插入到 word_count 中。
读取新插入的元素，并将它的值赋为 1。
使用下标访问 map 与使用下标访问数组或 vector 的行为截然不同：用下标访问不存在的元素将导致在 map 容器中添加一个新元素，它的键即为该下标值。
有别于 vector 或 string 类型，map 下标操作符返回的类型与对 map 迭代器进行解引用获得的类型不相同。显然，map 迭代器返回 value_type 类型的值
——包含 const key_type 和apped_type 类型成员的 pair 对象；下标操作符则返回一个 mapped_type 类型的值。
map< string, int > word_count;
while (cin >> word)
++word_count[word];
1
2
3
1
2
3
这段程序创建一个 map 对象，用来记录每个单词出现的次数。while 循环每次从标准输入读取一个单词。如果这是一个新的单词，则在 word_count 中添加以该单词
为索引的新元素。如果读入的单词已在 map 对象中，则将它所对应的值加 1。
*/
//参考ttps://zhidao.baidu.com/question/286211809.html
//介绍map的key与value ttp://blog.csdn.net/wangbingcsu/article/details/47439275