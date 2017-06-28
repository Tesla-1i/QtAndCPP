
/*．数制的转换
把一个10进制的整数m(0<m< 216)转换成n进制数（n = 2, 8或16 ），在主函数中输入m和n值，在主函数中输出转换后的序列 。
1）用非递归算法实现
2）用递归算法实现
*/

#include<iostream>
using namespace std;

int func1(int n, int p,int *s){
	int c, m = 0;
	while (n != 0){
		c = n%p;	//c是余数
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
		return func2(b, p);	//递归算法
	else return 0;
}

int main(){
	int n, p, s[100];
	cout << "输入转换的数字和进制\n";
	cin >> n >> p;
	int m = func1(n, p, s);
	for (int k = m; k >= 1; k--){
		if (s[k] >= 10)		//十六进制转化成字符.
			cout << (char)(s[k] + 55);
		else
			cout << s[k];
	}
	cout << endl;
	func2(n, p);
	for (int i = number - 1; i >= 0; i--){
		if (num[i] >= 10)		//十六进制转化成字符.
			cout << (char)(num[i] + 55);
		else
			cout << num[i];
	}
	cout << endl;
	return 0;
}

//递归ttp://blog.csdn.net/longzaitianya1989/article/details/8117718
//转任意进制ttp://blog.csdn.net/xiaofei2010/article/details/7434737