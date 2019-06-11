#include<iostream>

using namespace std;

int pow(int x,int n)
{
	if(n==0)
	{
		return 1;	
	}	
	
	return x*pow(x,n-1);
}

void printdigit(int n)
{
	switch(n)
	{
		case 1 : cout<<" one";
				break;
		
		case 2 : cout<<" two";
				break;
		case 3 : cout<<" three";
				break;
		case 4 : cout<<" four";
				break;
		case 5 : cout<<" five";
				break;
		case 6 : cout<<" six";
				break;
		case 7 : cout<<" seven";
				break;
		case 8 : cout<<" eight";
				break;
		case 9 : cout<<" nine";
				break;
		case 0 : cout<<" zero";
				break;
	}
	return;
}

int num2word(int n)
{
	if(n<10)
	{
		printdigit(n);
		return n;
	}
	 num2word(n/10);
	printdigit(n%10);
	return n/10;
}

bool check(int arr[],int n,int i)
{
	if(n==i)
	{
		return false;
	}
	
	if(arr[i]==7)
	{
		return true;
	}
	
	return check(arr,n,i+1);
}

int firstindex(int arr[],int n,int i )
{
	if(n-1==i)
	{
		return -1;
	}
	if(arr[i]==7)
	{
		return i ;
	}
	return firstindex(arr,n,i+1);
	
}

int lastindex(int arr[],int n,int i )
{
	if(0==i)
	{
		return -1;
	}
	if(arr[i]==7)
	{
		return i ;
	}
	return lastindex(arr,n,i-1);
	
}

int allindex(int arr[],int n,int i )
{
	if(arr[i]==7)
	{ 	
		cout<<i<<endl;
		
	}
	if(n-1==i)
	{
		return -1;
	}
	
	return allindex(arr,n,i+1);
	
}

int slastindex(int arr[],int n,int i)
{
	if(n==i)
	{
		return -1;
	}
	int x =slastindex(arr,n,i+1); 
	if(x != -1)
	{
		return x;
	}
	if(arr[i]==7)
	return i;
	
	return -1;
}

void bubblesort(int arr[],int n,int i,int max)
{
	if(i==n-1)
	{
		return;
	}
	bubblesort(arr,n,i+1);
	if(arr[i]>arr[i+1])
	{
		int temp;
		temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
	}
	return;
}

int main()
{
	int arr[10] = {2,1,9,4,3,5,7,8};
	//cout<<check(arr,5,0);
	//num2word(-2048);
	//printdigit(8);
	cout<<slastindex(arr,8,0);
	//bubblesort(arr,7,0);
	//allindex(arr,7,0);
/*	for(int i = 0;i<7;i++)
	{
		cout<<arr[i]<<endl;
	}
*/	
}
