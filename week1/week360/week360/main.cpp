#include<iostream>
#include<map>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;

void main()
{

	cout << "������������.��β" << endl;
	string s;
	map<string, int>p;
	do
	{
		cin >> s;
		p[s]++;		//?�ؼ����ڡ�

	} while (s != ".");
	for (map<string, int>::iterator iter = p.begin(); iter != p.end(); ++iter)
	{
		if ((iter->first) != ".")
			cout << iter->first << "   " << iter->second << endl;
	}
}


/*
��map�������Ԫ�أ���ʹ�� insert ��Աʵ�֣����ߣ������±��������ȡԪ�أ�Ȼ�����ȡ��Ԫ�ظ�ֵ��
ʹ���±����map��
map< string, int > word_count;
word_count["WB"] = 1;
1
2
1
2
�������������飺
�� word_count �в��Ҽ�Ϊ WB ��Ԫ�أ�û���ҵ���
��һ���µļ���ֵ�Բ��뵽 word_count �С����ļ��� const string ���͵Ķ��� ���� WB�� ������ֵ�����ֵ��ʼ���� �����ζ���ڱ�����ֵΪ 0��
������µļ���ֵ�Բ��뵽 word_count �С�
��ȡ�²����Ԫ�أ���������ֵ��Ϊ 1��
ʹ���±���� map ��ʹ���±��������� vector ����Ϊ��Ȼ��ͬ�����±���ʲ����ڵ�Ԫ�ؽ������� map ���������һ����Ԫ�أ����ļ���Ϊ���±�ֵ��
�б��� vector �� string ���ͣ�map �±���������ص�������� map ���������н����û�õ����Ͳ���ͬ����Ȼ��map ���������� value_type ���͵�ֵ
�������� const key_type ��apped_type ���ͳ�Ա�� pair �����±�������򷵻�һ�� mapped_type ���͵�ֵ��
map< string, int > word_count;
while (cin >> word)
++word_count[word];
1
2
3
1
2
3
��γ��򴴽�һ�� map ����������¼ÿ�����ʳ��ֵĴ�����while ѭ��ÿ�δӱ�׼�����ȡһ�����ʡ��������һ���µĵ��ʣ����� word_count ������Ըõ���
Ϊ��������Ԫ�ء��������ĵ������� map �����У���������Ӧ��ֵ�� 1��
*/
//�ο�ttps://zhidao.baidu.com/question/286211809.html
//����map��key��value ttp://blog.csdn.net/wangbingcsu/article/details/47439275