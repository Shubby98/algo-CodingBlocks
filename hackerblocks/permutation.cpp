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
		int min = s[i];
		int minindex = i;
		for(int j = i+1;j<n;j++)
		{
			if((int)s[j] < (int)min)
			{
				minindex = j;
			}
			
		}
		swap(s,i,minindex);
	}
	//cout<<s<<endl;
}

void permutation(string s,int i)
{
	if(s[i]=='\0')
	{
		cout<<s<<endl;
		return;
	}
	
	for(int j=i;s[j]!='\0';j++)
	{
		swap(s,i,j);
		if(   i==j || s[i]!=s[j])
		{	
			permutation(s,i+1);	
		}
		swap(s,i,j);
	}
	
}

int main()
{
	string s;
	cin>>s;
	sort(s);
	//cout<<s<<endl;
	permutation(s,0);
	//swap(s,1,2);
	
	
}
