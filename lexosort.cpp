#include<iostream>

using namespace std;

void swap(char s[1000][100],int j)
{
	int i = 0;
	char temp[100];
	for(i = 0; s[j][i] != '\0';i++)
	{
		temp[i] = s[j][i]; 
	}
	temp[i] = '\0';
	
	for(i = 0;s[j+1][i] != '\0';i++)
	{
		s[j][i] = s[j+1][i]; 
	}
	s[j][i] = '\0';
	
	for(i = 0;temp[i] !='\0';i++)
	{
		s[j+1][i] = temp[i]; 
	}
	s[j+1][i] = '\0';
	
	return;
}



void lexosort( char s[1000][100],int n)
{
	for(int i = 0 ;i<n;i++)
	{
		for(int j = 0; j<n-i-1 ;j++)
		{
			int k =0;
			while(s[j][k] == s[j+1][k] && s[j][k] != '\0')
			{
				k++;
			}
			
			//cout<<k<<endl;
			
			if(s[j][k]>s[j+1][k])
			{
			//	cout<<"swap"<<endl;
				swap(s,j);
			}
			
		}
	}
	return ;
}


int main()
{
	int n;
	cin>>n;

	char s[n][100];
	
	for(int i = 0;i<n;i++)
		cin>>s[i];
/*	
	for(int i = 0;i<n;i++)
	{
		for(int j =0;s[i][j] != '\0';j++)
		{
			cout<<s[i][j];
		}
	cout<<endl;
	}
*/	
	lexosort(s,n);
	
	for(int i = 0;i<n;i++)
	{
		for(int j =0;s[i][j] != '\0';j++)
		{
			cout<<s[i][j];
		}
	cout<<endl;
	}
	
	
}
