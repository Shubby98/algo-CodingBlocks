#include<iostream>
#include<time.h>
using namespace std;
/*
bool IsSafe(int arr[100][100],int x,int y,int n)
{
	for(int i = x, j = 0;(i<n && j<n)  (i>0 && j>0); j++)
	{
		if(arr[j][i] == 1 )
		{
			if(j!=y && i!=x)
			{
				return false;
			}
			
		}
	}
	
	for(int i = 0, j = y;(i<n && j<n)&& (i>0 && j>0); i++)
	{
		if(arr[j][i] == 1 )
		{
			if(j!=y && i!=x)
			{
				return false;
			}
		}
	}
	
		
	for(int i = x , j = y ;(i<n && j<n)&& (i>0 && j>0); i++,j++)
	{
		if(arr[j][i] == 1 )
		{
			if(j!=y && i!=x)
			{
				return false;
			}	
		}
	}
	for(int i = x , j = y ;(i<n && j<n)&& (i>0 && j>0); i--,j--)
	{
		if(arr[j][i] == 1 )
		{
			if(j!=y && i!=x)
			{
				return false;
			}	
		}
	}
	
	for(int i = x, j = y ;(i<n && j<n)&& (i>0 && j>0); i--,j++)
	{
		if(arr[j][i] == 1 )
		{
			if(j!=y && i!=x)
			{
				return false;
			}
		}
	}
	
	for(int i = x, j = y ;(i<n && j<n)&& (i>0 && j>0); i++,j--)
	{
		if(arr[j][i] == 1 )
		{
			if(j!=y && i!=x)
			{
				return false;
			}
		}
	}
	return true;
}
*/

bool IsSafe2(int arr[100][100],int n,int x,int y){
    int check[8][2] =  {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    for(int k=0;k<8;k++){
        for(int i=x+check[k][0],j=y+check[k][1];i<n && i>=0 &&j<n && j>=0;i+=check[k][0],j+=check[k][1]){
            if(arr[i][j]==1){
                return false;
            }
        }
    }
    return true;
}
int Nqueen(int arr[100][100],int n,int y)
{
	if(y>=n)
	{
		/*
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				if(arr[i][j] == 1)
				{
					cout<<"{"<<i+1<<"-"<<j+1<<"}"<<" ";
				}
			}
		}*/
		/*for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				//if(arr[i][j] == 1)
				//{
					cout<<arr[i][j];
				//}
			}
			cout<<endl;
		}*/
		//cout<<" ";
		return 1;
	}
	
	int sum =0;
	for(int i = 0;i<n;i++)
	{
		
		if(IsSafe2(arr,n,i,y))
		{
			arr[i][y] = 1;
			sum += Nqueen(arr,n,y+1);
			
			
			arr[i][y] = 0;
			
		}
	}
	return sum;
	
	
	
	
}

int main()
{
	int n,count;
	cin>>n;
	clock_t start = clock();
	int arr[100][100] = {0};
	cout<<Nqueen(arr,n,0)<<endl;
	clock_t end = clock();
	//cout<<"time = "<<end-start;
	
}
