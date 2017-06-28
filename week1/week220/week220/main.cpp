#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main(){
	char name[5][20], *temp;
	char *pname[5];
	//pname[0] = name[0];
	int i, j;
	cout << "依次输入五个国家名\n";
	for (i = 0; i < 5; i++)
		cin >> (name[i]);
	for (i = 0; i < 5; i++){
		pname[i] = new char[20];	//申请空间,错误的原因.
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
		delete[] pname[i];	//释放空间；
	}
	cout << endl;
	return 0;
}

/*预测进入亚洲杯4强名单
如何存储5个长度不同的字符串？
输入5个国家名（英文名即可），按字母表顺序输出*/
