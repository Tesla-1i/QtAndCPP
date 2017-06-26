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






/*#include<iostream>
using namespace std;

//求等于target的最小元素位置。
int searchMin(int *dArr, int n, int target){
	//cout << "11 ";
	int start = 0, end = n - 1;
	while (start <= end){
		//cout << "111 ";
		int mid = (start + end) / 2;
		if (dArr[mid] == target){
			//中间元素左边元素等于目标元素
			if (mid - 1 >= 0 && dArr[mid - 1] == target){
				end = mid - 1;
			}
			else
			{
				//cout << "1 ";
				return mid;
				break;	//没有不行，跳出循环，
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
//求等于target的最大元素位置
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

/*参考资料
ttp://yq.aliyun.com/articles/3670
ttp://blog.csdn.net/u014609111/article/details/53508068
ttp://www.cnblogs.com/yjmyzz/p/4212149.html
*/