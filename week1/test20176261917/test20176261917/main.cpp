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

int main(){
	int A[] = { 1, 2, 4, 4, 4, 4, 4, 5, 6, 7, 8 };
	cout << "Count->" << BinarySearchCount(A, 11, 4) << endl;
	return 0;
}