#include <bits/stdc++.h> 
using namespace std; 
int cntrot(int arr[], int low, int high) 
{ 
	if (high < low) 
		return 0; 
	if (high == low) 
		return low; 
	int mid = low + (high - low) / 2;
	if (mid < high && arr[mid + 1] < arr[mid]) 
		return (mid + 1); 
	if (mid > low && arr[mid] < arr[mid - 1]) 
		return mid; 
	if (arr[high] > arr[mid]) 
		return cntrot(arr, low, mid - 1); 

	return cntrot(arr, mid + 1, high); 
} 
int main() 
{ 
	int arr[10] = {5,6,7,8,9,10,1,2,3,4}; 
	cout << cntrot(arr, 0, 9); 
	return 0; 
}
