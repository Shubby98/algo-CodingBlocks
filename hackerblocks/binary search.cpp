#include<iostream>

using namespace std;

long int Binary_search(int arr[],int n,int num)
{
	long int start = 0,end = n-1;
	while(start<=end)
	{
		//cout<<"**";
		long int mid = start + (end-start)/2;
		//cout<<mid<<endl;
		if(arr[mid] == num)
			return mid;
		else if(arr[mid]>num)
			end=mid-1;
		else if(arr[mid]<num)
			start = mid+1;
	}
	return -1;
}

int main() {
    long int m,n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>m;
    cout<<Binary_search(arr,n,m)<<endl;
	return 0;
}
