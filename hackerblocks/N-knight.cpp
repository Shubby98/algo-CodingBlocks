#include<iostream>
#include<time.h>

using namespace std;

bool IsSafe(int arr[100][100],int n,int x,int y)
{
	bool left =  true, right =  true, up = true, down = true;
	if(x+2>n-1)
	{
		right = false;
	}
	if(x-2<0)
	{
		left = false;
	}
	if(y+2>n-1)
	{
		down = false;
	}
	if(y-2<0)
	{
		up = false;
	}
	
	if(right)
	{
		if(arr[y-1][x+2] ==1 || arr[y+1][x+2] == 1)
		{
			return false;
		}
	}
	if(left)
	{
		if(arr[y-1][x-2] ==1 || arr[y+1][x-2] == 1)
		{
			return false;
		}
	}
	
	if(up)
	{
		if(arr[y-2][x+1] ==1 || arr[y-2][x-1] == 1)
		{
			return false;
		}
	}
	
	if(down)
	{
		if(arr[y+2][x+1] ==1 || arr[y+2][x-1] == 1)
		{
			return false;
		}
	}
	return true ; 

	
	
	
}

int NKnight(int arr[100][100],int n,int x,int y,int i)
{
	//base condition
	if(i == n )
	{
		//cout<<"x="<<x<<"  y="<<y<<"  i="<<i<<endl;
		for(int j = 0;j<n;j++)
		{
			for(int k = 0;k<n;k++)
			{
				//cout<<arr[j][k]<<" ";
				if(arr[j][k] == 1)
				{
					cout<<"{"<<j<<"-"<<k<<"} ";	
				}	
			}
			//cout<<endl;	
		}
		cout<<" ";
		//cout<<endl<<endl;
		return 1;	
	}
	if( x==n && y == n-1 )
	{
		//cout<<"x="<<x<<"  y="<<y<<"  i="<<i<<endl;
		return 0;
	}
	
	if(x == n)
	{
		//cout<<"x="<<x<<"  y="<<y<<"  i="<<i<<endl;
		return NKnight(arr,n,0,y+1,i);
	}
	int sum = 0;
	
	for(int j = y;j<n;j++)
	{
		int k;
		if(j == y)
		{
			 k = x;
		}
		else
		{
			k = 0;
		}
		for(;k<n;k++)
		{
			if(IsSafe(arr,n,k,j))
			{
				
			//cout<<"x="<<j<<"  y="<<k<<"  i="<<i<<endl;
			arr[j][k] = 1;
			sum += NKnight(arr,n,k+1,j,(i+1));
			arr[j][k] = 0;
			
			}
		}
	}
	
	return sum;
	
	
}




int main()
{
	int n;
	cin>>n;
	int arr[100][100] = {0};
	//clock_t start = clock();
	cout<<NKnight(arr,n,0,0,0)<<endl;
	//clock_t end = clock();
	//cout<<end - start<<endl;
}
