#include<bits/stdc++.h>

using namespace std;

void heapify(int arr[],int i,int n)
{
		int minIndex = i;
		int left = 2*i;
		int right = left + 1;
		if(left < n && arr[minIndex] > arr[left])
		{
			minIndex = left;
		}
		if(right < n && arr[minIndex] > arr[right])
		{
			minIndex = right;
		}
		if(minIndex!=i)
		{
			swap(arr[i],arr[minIndex]);
			heapify(arr,minIndex,n);
		}
		return ;
	
}

void heapsort(int * arr,int n)
{
	for(int i = n/2 ;i>0 ;i--)
	{
		heapify(arr,i,n);
	}
	
	for(int i = n-1 ; i>0;i--)
	{
		swap(arr[i],arr[1]);
		heapify(arr,1,i);
	}
}

void print(int arr[],int n)
		{
			for(int i = 1;i<n;i++)
			{
				cout<<arr[i]<<" ";
			}
			return ;
		}

int main()
{
	int arr[10] = {-1,5,8,3,9,2,0,6};
	heapsort(arr,7);
	print(arr,7);
	
}
