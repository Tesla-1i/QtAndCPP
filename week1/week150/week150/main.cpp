
/*�����Ƶ�ת��
��һ��10���Ƶ�����m(0<m< 216)ת����n��������n = 2, 8��16 ������������������m��nֵ���������������ת��������� ��
1���÷ǵݹ��㷨ʵ��
2���õݹ��㷨ʵ��
*/

#include<iostream>
using namespace std;

int func1(int n, int p,int *s){
	int c, m = 0;
	while (n != 0){
		c = n%p;	//c������
		n = n / p;
		m++;
		s[m] = c;
	}
	return m;
}

int num[100];
int number = 0;
int func2(int n, int p){
	int a, b;
	a = n%p;
	b = n / p;
	num[number++] = a;
	if (b != 0)
		return func2(b, p);	//�ݹ��㷨
	else return 0;
}

int main(){
	int n, p, s[100];
	cout << "����ת�������ֺͽ���\n";
	cin >> n >> p;
	int m = func1(n, p, s);
	for (int k = m; k >= 1; k--){
		if (s[k] >= 10)		//ʮ������ת�����ַ�.
			cout << (char)(s[k] + 55);
		else
			cout << s[k];
	}
	cout << endl;
	func2(n, p);
	for (int i = number - 1; i >= 0; i--){
		if (num[i] >= 10)		//ʮ������ת�����ַ�.
			cout << (char)(num[i] + 55);
		else
			cout << num[i];
	}
	cout << endl;
	return 0;
}

//�ݹ�ttp://blog.csdn.net/longzaitianya1989/article/details/8117718
//ת�������ttp://blog.csdn.net/xiaofei2010/article/details/7434737