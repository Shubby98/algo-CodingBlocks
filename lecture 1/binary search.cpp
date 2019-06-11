#include<iostream>
using namespace std;

bool Binary_search(int arr[],int n,int num)
{
	int start = 0,end = n-1;
	while(start<end)
	{
		//cout<<"**";
		int mid = start + (end-start)/2;
		if(arr[mid] == num)
			return true;
		if(arr[mid]>num)
			end=mid;
		if(arr[mid]<num)
			start = mid+1;
	}
	return false;
}
void printarr(int arr[],int n)
{
	for(int i = 0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void Insertion_sort(int arr[],int n)
{
	int key , j;
	for(int i =  1; i<=n;i++)
	{
		 key = arr[i] ;
		 j = i-1;
		
		while(j>=0 && key<arr[j])
		{
			arr[j+1] = arr[j];
			j--;
			
		}
		arr[j+1] = key;
		
		
		
	}
}

void pa(int arr[],int n, int x)
{
	for(int i = 0 ; i<n;i++)
	{
		for(int j = i ; j<n;j++)
		{
			if(arr[i]+arr[j] ==x)
			{
				cout<<"("<<arr[i]<<arr[j]<<")"<<endl;
			}
		}
	}
	return;
}

int medin(int arr1[],int arr2[],int n,int m)
{
	int i = 0,j = 0;
	int index = 0,median;
	int mid = (n+m)/2;
	while(i<n && j <m)
	{
		if(arr1[i]<arr2[j])
		{
				median = arr1[i];
				index++;
				i++;
		}
		else
		{
				median = arr2[j];
				index++;
				j++;
		}
		//cout<<median<<" ";
		if(index == mid)
		{
			cout<<endl;
			return median;
		}
	}
}


int main()
{
	int arr[10] = {3,5,6,8,9,12,34,52};
	int arr1[10] = {2 ,4,6 ,8 ,10};
	//cout<<Binary_search(arr,8,12)<<endl;
	//pa(arr1,8,11);
	//Insertion_sort(arr1,5);
	cout<<medin(arr,arr1,8,5);
}
