#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int partition(int *array, int left, int right)
{
	if (array == NULL)
		return -1;
	
	int pos = right;
	right--;
	while (left <= right)
	{
		while (left < pos && array[left] <= array[pos])
			left++;
		
		while (right >= 0 && array[right] > array[pos])
			right--;
		
		if (left >= right)
			break;
		
		swap(array[left], array[right]);
	}
	swap(array[left], array[pos]);
	
	return left;
}

int getMidIndex(int *array, int size)
{
	if (array == NULL || size <= 0)
	return -1;
	
	int left = 0;
	int right = size - 1;
	int midPos = right >> 1;
	int index = -1;
	
	while (index != midPos)
	{
		index = partition(array, left, right);
		
		if (index < midPos)
			left = index + 1;
		else if (index > midPos)
			right = index - 1;
		else break;
	}
	
	//assert(index == midPos);
	return array[index];
}   
     
int minmov(int *A, int n){
	int sum = 0;
	int mean = getMidIndex(A, n);
	int ans = 0;
	for (int i=0; i<n; ++i){
		ans += abs(A[i]-mean);
	}
	return ans;
}

int main(){
	int A[3] = {1,2,3};
	int n=3;
	cout<<minmov(A, n);
} 
