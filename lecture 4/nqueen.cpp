#include<iostream>

using namespace std;

bool isSafe(int arr[100][100],int n,int x,int y)
{
	
	for(int i = x+1,j=y; i<n && i >=0 ;i++ )
	{
		if(arr[i][j] == 1)
		{
			return false;
		}
	}
	
	for(int i = x-1,j=y; i<n && i >=0 ;i-- )
	{
		if(arr[i][j] == 1)
		{
			return false;
		}
	}
	
	for(int i = x,j=y+1; j<n && j >=0 ;j++ )
	{
		if(arr[i][j] == 1)
		{
			return false;
		}
	}
	
	for(int i = x,j=y-1; j<n && j >=0 ;j-- )
	{
		if(arr[i][j] == 1)
		{
			return false;
		}
	}
	
	for(int i = x-1,j=y-1; i<n && i >=0 && j<n && j >=0 ;i--,j-- )
	{
		if(arr[i][j] == 1)
		{
			return false;
		}
	}
	
	for(int i = x+1,j=y-1; i<n && i >=0 && j<n && j >=0 ;i++,j-- )
	{
		if(arr[i][j] == 1)
		{
			return false;
		}
	}
	
	for(int i = x+1,j=y+1; i<n && i >=0 && j<n && j >=0 ;i++,j++ )
	{
		if(arr[i][j] == 1)
		{
			return false;
		}
	}
	
	for(int i = x-1,j=y-1; i<n && i >=0 && j<n && j >=0 ;i--,j++ )
	{
		if(arr[i][j] == 1)
		{
			return false;
		}
	}
	
}

int nQueen(int arr[100][100],int n,int x,int y)
{
	if(y == n)
	{
		cout<<endl;
		cout<<"---------------------------------------------"<<endl;
		for(int i = 0; i<n;i++)
		{
			for(int j =0 ;j<n ;j++)
			{
				if(arr[i][j])
				{
					cout<<"#";
				}
				else
				{
					cout<<"-";
				}
			}
			cout<<endl;
		}
		return 1;
	}
	
	int count = 0;
	for(int i = 0;i<n;i++)
	{
		if(isSafe(arr,n,i,y))
		{
			arr[i][y] = 1;
			/*bool done = nQueen(arr,n,0,y+1);
			if(done)
			{
				return true;
			}*/
			count += nQueen(arr,n,0,y+1);
			arr[i][y] = 0;
			
		}
	}
	return count;
}


int main()
{
	int arr[100][100] = {0};
	cout<<nQueen(arr,5,0,0);
}
