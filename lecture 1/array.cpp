#include<iostream>
#include<climits>

using namespace std;

int sumofarr(int arr[],int n)
{
	int sum= 0;
	for(int i = 0; i<n;i++)
	{
		sum+= arr[i];
	}
	return sum;
}

void selection_sort(int arr[10],int n)
{
	for(int i = 0;i< n;i++)
	{
		int min = INT_MAX;
		int min_index = i;
		for(int j = n; j>0 ; j--)
		{
			if(min>arr[j])
				min = arr[j];
				min_index = j;
		}
		cout<<min<<endl;
		int temp =  arr[i];
		arr[i]=min;
		arr[min_index] = temp;
	}
}

int main()
{
	int arr[10] = {5,4,3,2,1};
	
	cout<<sumofarr(arr,5)<<endl;
	selection_sort(arr,5);
	for (int i = 0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
}
