#include<iostream>

using namespace std;


void print(int arr[100][100],int n)
{
	cout<<endl<<endl;
	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";	
		}
		cout<<endl;
	}
	
	cout<<endl;
	return;

}
bool solver(int arr[100][100],int n,int x,int y,int num)
{
	for(int i = 0;i<n;i++)
	{
		if(arr[y][i] == num || arr[i][x] == num)
		{
			return false;
		}
	}
	
	int x1 = 3*(x/3);
	int y1 = 3*(y/3);
	
	for(int i =x1;i<x1+3;i++)
	{
		for(int j =y1;j<y1+3;j++)
		{
			if(arr[j][i] == num){
				return false;
			}
		}
	}
	return true;
	
}

bool sudoko(int arr[100][100],int n,int x,int y)
{
	//cout<<y<<x<<endl;
	if(y==n-1 && x==n)
	{
		print(arr,n);
		return true;
	}
	if(x>=n)
	{
		return sudoko(arr,n,0,y+1);
	}
	if(arr[y][x] == 0)
	{
		for(int val = 1;val<=9;val++)
		{
			if(solver(arr,n,x,y,val))
			{
				arr[y][x]=val;
				if(sudoko(arr,n,x+1,y))
					return true;
					
				arr[y][x] = 0;
			}
		}
	}
	else
	{
		return sudoko(arr,n,x+1,y);
	}
	return false;
}

int main()
{
	int n ;
	cin>>n;
	int arr[100][100];
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cin>>arr[i][j];
			
		}
	}
	sudoko(arr,n,0,0);
		
	return 0;
}
