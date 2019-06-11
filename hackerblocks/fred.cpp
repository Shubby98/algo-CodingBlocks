#include<iostream>

using namespace std;

int min(int a,int b,int c)
{
	int min = a;
	if(min>b)
	{
		min = b;
	}
	if(min>c)
	{
		min = c;
	}
	return min;
}

int steps(int n)
{
	if(n==1)
	{
		return 0;
	}
	
	int a=1000,b=1000,c=1000;
	if(n%3==0)
	{
		a = steps(n/3);
	}
	if(n%2==0)
	{
		b = steps(n/2);
	}
	c=steps(n-1);
	return min(a,b,c)+1;
	
}

int main()
{
	int n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<steps(n)<<endl;
	
	}
}
