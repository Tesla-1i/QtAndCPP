#include <iostream>
using namespace std;

int search(int *dArr, int len, int key){
	cout << "1" << endl;
	int middle, num = 0, low = 0, high = len - 1;
	while (low <= high){
		middle = (high + low) / 2;
		if (dArr[middle] == key)
		{
			return middle;
			cout << "num" << num << endl;
		}
		else if (dArr[middle] > key)
			high = middle - 1;
		else
		{
			low = middle + 1;
		}
	}
	
	cout << "2" << endl;
	return -1;
}

int main(){
	int array1[6];
	cout << "ð������,��������������" << endl;
	int i=0, j=0, temp=0, compare = 0,change = 0 ;
	/*for ( i = 0; i < 6; i++)
	{
		cin >> array1[i];
	}
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5 - i; j++){
			compare++;
			if (array1[j] > array1[j + 1]){
				change = change + 3;
				temp = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 6; i++)
		cout << array1[i] << " " ;
	cout << "" << endl;
	cout << "compare : " << compare << " change " << change << endl;
	////////////////////////////////////////////////////
	compare = 0; change = 0;
	///////////////////////////////////////////////////
	cout << "ѡ�������������������� " << endl;
	for (i = 0; i < 6; i++)
	{
		cin >> array1[i];
	}
	int index;	//Ѱ�ҵ���С���±��
	for (i = 0; i < 5; i++){
		index = i;
		for (j = i + 1; j < 6; j++){
			compare++;
			if (array1[j] < array1[index])
				index = j;
		}
		if (index != i){
			change = change + 3;
			temp = array1[i];
			array1[i] = array1[index];
			array1[index] = temp;
		}
	}
	for (i = 0; i < 6; i++){
		cout << array1[i] << " ";
	}
	cout << " " << endl;
	cout << "compare: " << compare << " change: " << change << endl;
	/////////////////////////////////
	compare = 0; change = 0;
	////////////////////////////////
	cout << "��������; ��������������" << endl;
	for (i = 0; i < 6; i++)
	{
		cin >> array1[i];
	}
	for (i = 1; i < 6; i++){
		j = i - 1;//�Ժ���ǰ����
		temp = array1[i];
		compare++;
		while (j >= 0 && array1[j] > temp){
			change++;
			array1[j + 1] = array1[j];
			j--;
		}
		if (j != i - 1){
			change++;
			array1[j + 1] = temp;
		}
	}
	for (i = 0; i < 6; i++)
		cout << array1[i] << " ";
	cout << "\ncompare: " << compare << " change: " << change << endl;
	/////////////////////////////
	compare = 0; change = 0;
	/////////////////////////////*/
	cout << "����������ֲ��ң�" << endl;
	int dArr[10] = { 1, 1, 3, 4, 4, 6,8, 8, 9,10 };
	for (i = 0; i < 10; i++){
		cout << dArr[i] << " ";
	}
	cout << "������ҵ�Ԫ��: ";
	int key;
	cin >> key;
	int num = search(dArr, 10, key);
	cout << key << " ����: " << num << endl;
	return 0;
}