#include <iostream>
using namespace std;
// �����target����СԪ��λ��
int BinarySearchMin(int A[], int n, int target){
	if (n <= 0){
		return -1;
	}//if
	int start = 0, end = n - 1;
	// ���ֲ��ұ���
	while (start <= end){
		int mid = (start + end) / 2;
		if (A[mid] == target){
			// ����м�Ԫ�����Ԫ�ص���Ŀ��Ԫ��
			if (mid - 1 >= 0 && A[mid - 1] == target){
				end = mid - 1;
			}//if
			else{
				return mid;
			}
		}//if
		// Ŀ��λ����벿��
		else if (A[mid] > target){
			end = mid - 1;
		}
		// Ŀ��λ���Ұ벿��
		else{
			start = mid + 1;
		}//else
	}//while
	return -1;
}
// �����target�����Ԫ��λ��
int BinarySearchMax(int A[], int n, int target){
	if (n <= 0){
		return -1;
	}//if
	int start = 0, end = n - 1;
	// ���ֲ��ұ���
	while (start <= end){
		int mid = (start + end) / 2;
		// �м�Ԫ�ص���Ŀ��
		if (A[mid] == target){
			// ����м�Ԫ���ұ�Ԫ�ص���Ŀ��Ԫ��
			if (mid + 1 < n && A[mid + 1] == target){
				start = mid + 1;
			}//if
			else{
				return mid;
			}//else
		}//if
		else if (A[mid] > target){
			end = mid - 1;
		}//else
		else{
			start = mid + 1;
		}
	}//while
	return -1;
}

int BinarySearchCount(int A[], int n, int target){
	int min = BinarySearchMin(A, n, target);
	int max = BinarySearchMax(A, n, target);
	// û��
	if (min == -1){
		return 0;
	}//if
	int count = max - min + 1;
	return count;
}






/*#include<iostream>
using namespace std;

//�����target����СԪ��λ�á�
int searchMin(int *dArr, int n, int target){
	//cout << "11 ";
	int start = 0, end = n - 1;
	while (start <= end){
		//cout << "111 ";
		int mid = (start + end) / 2;
		if (dArr[mid] == target){
			//�м�Ԫ�����Ԫ�ص���Ŀ��Ԫ��
			if (mid - 1 >= 0 && dArr[mid - 1] == target){
				end = mid - 1;
			}
			else
			{
				//cout << "1 ";
				return mid;
				break;	//û�в��У�����ѭ����
			}
		}
		else if (dArr[mid] > target)
		{
			end = mid - 1;
		}
		else
		{
			start = mid - 1;
		}
	}
	return -1;
}
//�����target�����Ԫ��λ��
int searchMax(int *dArr, int n, int target){
	//cout << "22 ";
	int start = 0, end = n - 1;
	while (start <= end){
		int mid = (start + end) / 2;
		if (dArr[mid] == target){
			if (mid + 1 < n&&dArr[mid + 1] == target){
				start = mid + 1;
			}
			else{
				//cout << "2 ";
				return mid;
			}
		}
		else if(dArr[mid]>target){
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}

int search(int dArr[], int n, int target){
	int min = searchMin(dArr, n, target);
	int max = searchMax(dArr, n, target);
	//cout << " 3";
	if (min == -1)
		return 0;
	int count = max - min + 1;
	return count;
}

/*�ο�����
ttp://yq.aliyun.com/articles/3670
ttp://blog.csdn.net/u014609111/article/details/53508068
ttp://www.cnblogs.com/yjmyzz/p/4212149.html
*/