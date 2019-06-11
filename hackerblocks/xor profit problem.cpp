#include<iostream>

using namespace std;

int myXOR(int x, int y) 
{ 
   return (x | y) & (~x | ~y); 
} 

int main()
{
	int a,b,xr,max=0;
	cin>>a>>b;
	for(int i = a; i<=b;i++)
	{
		for(int j =i; j<=b;j++)
		{
			xr = myXOR(i,j);
			if(max<xr)
				max = xr;
		}
	}
	
	cout<<max;
	return 0;
}
