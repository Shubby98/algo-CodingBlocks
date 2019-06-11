#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(string &s,int i,int j)
{
	char temp = s[i];
	s[i] = s[j];
	s[j] =temp;
	//cout<<s<<"****"<<endl;
	return;
}

void sort(string &s)
{
	int n = s.length();
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n - i -1;j++)
		{
			if(s[j] >s[j+1])
			{
				char temp = s[j];
				s[j] =  s[j+1];
				s[j+1] = temp;
			}
		}
	}
	//cout<<s<<endl;
}

void permutation(string &s,int i,char stop)
{
	if(s[i]=='\0')
	{
		if(s[0] >= stop)
		{
			return;
		}
		cout<<s<<endl;
		return ;
	}
	
	for(int j=i;s[j]!='\0';j++)
	{
		bool flag;
		swap(s,i,j);
		if(   i==j || s[i]!=s[j])
		{	
			 permutation(s,i+1,stop);	
		}
		swap(s,i,j);
		
	/*	if(flag == false)
		{
			return false;
		}*/
	}
	
}



int main()
{
	string s;
	cin>>s;
	
	char stop =  s[0];
	
	sort(s);
	
	
	permutation(s,0,stop);
	
	
}
