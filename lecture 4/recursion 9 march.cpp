#include<iostream>

using namespace std;

void merge(int arr[], int start1,int start2,int end )
{
	
	int i = start1,j=start2,k = 0;
	int narr[end]; 
	while(i<(start2) && j<(end) )
	{
		if(arr[i]<arr[j])
		{
			narr[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			narr[k] = arr[j];
			k++;
			j++;
		}
	}
	
	while(i<(start2 ))
	{
		narr[k] = arr[i];
		i++;
		k++;
	}
	
	while(j<end)
	{
		narr[k] = arr[j];
		j++;
		k++;
	}
	cout<<start1<<"->"<<end<<endl;
	for(int i = 0;i<k;i++)
	{
		cout<<narr[i]<" ";
	}
	return;
}

void mergesort(int arr[],int start,int end)
{
	if(start>=end)
	{
			return;
	}
	int mid = (start+end)/2;
	mergesort(arr,start,mid);
	
}

int main()
{
	int arr1[] = {1,3,7,2,5};
	int arr2[] = {2,5};
	merge(arr1,0,3,5);
	
}
