#include<iostream>

using namespace std;

bool Path(char arr[1001][1001],int path[1001][1001] ,int x,int y,int n,int m)
{
	if(x==m-1 && y == n-1)
	{
        path[y][x] = 1;
		return true;
	}

	bool done;


	if(x<m-1 && arr[y][x] != 'X' && path[y][x] != 1)
	{
        path[y][x] = 1;
		if(Path(arr,path,x+1,y,n,m))
		{
			return true;
		}
	}

    if(y<n-1 && arr[y][x] != 'X' && path[y][x] != 1)
	{
        path[y][x] = 1;
		if(Path(arr,path,x,y+1,n,m))
		{
			return true;
		}
	}

    if(x>0 && arr[y][x] != 'X' && path[y][x] != 1)
	{
        path[y][x] = 1;
		if(Path(arr,path,x-1,y,n,m))
		{
			return true;
		}
	}
     if(y>0 && arr[y][x] != 'X' && path[y][x] != 1)
	{
        path[y][x] = 1;
		if(Path(arr,path,x,y-1,n,m))
		{
			return true;
		}
	}

    path[y][x] = 0;
	return false;

}

int main()
{
	int n,m;
	cin>>n>>m;
	char arr[1001][1001];
	int path[1001][1001] ;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	Path(arr,path,0,0,n,m);

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			cout<<path[i][j];
		}
		cout<<endl;
	}
	return 0;
}
