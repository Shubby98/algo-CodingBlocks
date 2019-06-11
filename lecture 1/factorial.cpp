#include<iostream>

using namespace std;

int fact(int n)
{
	if(n==0)
		return 1;
	else
	{	
		int fact = 1;
		for(int i =n;i>0;i--)
		{
			fact *= i;
		}
		return fact;
	}
	
}

void nCr(int n,int r)
{
	int c = (fact(n))/(fact(r)*(fact(n-r)));
	cout<<n<<"C"<<r<<" = "<<c<<endl;
}

int main()
{
	for(int i = 0;i<=5;i++)
		nCr(5,i);
}
