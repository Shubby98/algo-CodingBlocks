#include<iostream>

using namespace std;

int Path(char way[],int i ,int n,int n1,int n2,int x,int y)
{
	if(x == n2 && y ==n1)
	{
		way[i] = '\0';
		cout<<way<<" ";
		return 1;
	}
	int count = 0;
	if(y < n1)
	{
		way[i] = 'V';
		count += Path(way,i+1,n,n1,n2,x,y+1);
	}
	if(x<n2)
	{
		way[i] = 'H';
		count += Path(way,i+1,n,n1,n2,x+1,y);
	}
	
	if((x<n2 && y<n1 ) && ((x == y) || (y == n1+1-x)))
	{
		way[i] = 'D';
		count += Path(way,i+1,n,n1,n2,x+1,y+1);
	}
	
	return count;

}

int main()
{
	int n1;
	cin>>n1;
	int n2 = n1;
	int n = n1 + n2 -2;
	char way[n];
	cout<<Path(way,0,n,n1,n2,1,1);
}
