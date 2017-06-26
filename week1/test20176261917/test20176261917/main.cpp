#include <iostream>
using namespace std;
// 求等于target的最小元素位置
int BinarySearchMin(int A[], int n, int target){
	if (n <= 0){
		return -1;
	}//if
	int start = 0, end = n - 1;
	// 二分查找变形
	while (start <= end){
		int mid = (start + end) / 2;
		if (A[mid] == target){
			// 如果中间元素左边元素等于目标元素
			if (mid - 1 >= 0 && A[mid - 1] == target){
				end = mid - 1;
			}//if
			else{
				return mid;
			}
		}//if
		// 目标位于左半部分
		else if (A[mid] > target){
			end = mid - 1;
		}
		// 目标位于右半部分
		else{
			start = mid + 1;
		}//else
	}//while
	return -1;
}
// 求等于target的最大元素位置
int BinarySearchMax(int A[], int n, int target){
	if (n <= 0){
		return -1;
	}//if
	int start = 0, end = n - 1;
	// 二分查找变形
	while (start <= end){
		int mid = (start + end) / 2;
		// 中间元素等于目标
		if (A[mid] == target){
			// 如果中间元素右边元素等于目标元素
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
	// 没有
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