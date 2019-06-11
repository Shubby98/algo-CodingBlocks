#include<iostream>

using namespace std;

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
	int n;
	cin>>n;
	int arr1[n],arr2[n];
	for(int i = 0;i<n ;i++)
	{
		cin>>arr1[i];
	}
	
	for(int i = 0;i<n ;i++)
	{
		cin>>arr2[i];
	}
	
	cout<<medin(arr1,arr2,n,n);
}
