#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main(){
	char name[5][20], *temp;
	char *pname[5];
	//pname[0] = name[0];
	int i, j;
	cout << "�����������������\n";
	for (i = 0; i < 5; i++)
		cin >> (name[i]);
	for (i = 0; i < 5; i++){
		pname[i] = new char[20];	//����ռ�,�����ԭ��.
		strcpy(pname[i], name[i]);
	}
	
	for (i = 0; i < 4; i++){
		for (j = 0; j < 5 - i - 1; j++){
			if (strcmp(pname[j], pname[j + 1])>0){
				temp = pname[j];
				pname[j] = pname[j + 1];
				pname[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 5; i++){
		cout << pname[i] << "\t";
		delete[] pname[i];	//�ͷſռ䣻
	}
	cout << endl;
	return 0;
}

/*Ԥ��������ޱ�4ǿ����
��δ洢5�����Ȳ�ͬ���ַ�����
����5����������Ӣ�������ɣ�������ĸ��˳�����*/
