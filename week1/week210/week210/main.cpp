#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	cout << "��������Ԫ�ظ����� ";
	int i;	cin >> i;
	int *p1 = new int[i];
	int *p2 = new int[i];
	cout << "��������\n";
	int j;
	for (j = 0; j < i; j++)
		cin >> (*(p1 + j));
	//������
	int k, temp;
	for (j = 0; j < i - 1; j++){
		for (k = 0; k < i - j - 1; k++){
			if (*(p1 + k)>*(p1 + k + 1)){
				temp = *(p1 + k);
				*(p1 + k) = *(p1 + k + 1);
				*(p1 + k + 1) = temp;
			}
		}
	}
	j = 0; k = 1;
	*(p2 + j) = *(p1 + j);
	for (j = 1; j < i; j++){
		if (*(p1 + j) != *(p1 + j - 1)){
			*(p2 + k) = *(p1 + j);
			k++;
		}
	}
	cout << "�����飺\n";
	for (j = 0; j < k ; j++)
		cout << (*(p2 + j)) << " ";
	delete[] p1;
	delete[] p2;
	return 0;
}