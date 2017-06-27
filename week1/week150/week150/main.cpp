#include<iostream>
using namespace std;
void func(int m, int n){
	int i = 0, j;
	int b[32];
	switch (n)
	{
	case 2:{
			   if (m > 0){
				   b[i++] = m % 2;
				   m /= 2;
				   func(m, n);
			   }
			   b[i] = '\n';
			   for (j = i - 1; j >= 0; j--)
				   cout << b[j];
	}
	case 8:{
			   if (m > 0){
				   b[i++] = m % 8;
				   m /= 8;
				   func(m, n);
			   }
			   b[i] = '\n';
			   for (j = i - 1; j >= 0; j--)
				   cout << b[j];
	}
	case 16:{
			   if (m > 0){
				   b[i++] = m % 16;
				   m /= 16;
				   func(m, n);
			   }
			   b[i] = '\n';
			   for (j = i - 1; j >= 0; j--)
				   cout << b[j];
	}

	default:
		break;
	}
}

int main(){
	int m, n;
	cout << "输入十进制数m(1<m<216)，转化的进制n（2,8,16）\n";
	cin >> m >> n;
	switch (n)
	{
	case 2:{
			   int i = 0, j;
			   int b[32];
			   while (m > 0){
				   b[i++] = m % 2;
				   m /= 2;
			   }
			   for (j = i - 1; j >= 0; j--)
				   cout << b[j];
			   cout << endl;
	}
	case 8:{
			   int i = 0, j;
			   int b[32];
			   while (m > 0){
				   b[i++] = m % 8;
				   m /= 8;
			   }
			   for (j = i - 1; j >= 0; j--)
				   cout << b[j];
			   cout << endl;
	}
	case 16:{
			   int i = 0, j;
			   int b[32];
			   while (m > 0){
				   b[i++] = m % 16;
				   m /= 16;
			   }
			   for (j = i - 1; j >= 0; j--)
				   cout << b[j];
			   cout << endl;
	}
	default:
		break;
	}
	/////
	cout << "输入\n";
	cin >> m >> n;
	func(m, n);
	return 0;
}