#include<iostream>

using namespace std;

void nokiakeypad(string table[],string s,int inputindex,int n,
char output[],int outputindex)
{
	if(outputindex==n)
	{
		for(int j=0;j<n;j++)
		{
			cout<<output[j];
		}
		cout<<endl;
		return;
	}
	
	int keypadnum = s[inputindex]-48;
	
	for(int i=0;i<table[keypadnum].length();i++)
	{
		output[outputindex]=table[keypadnum][i];
		nokiakeypad(table,s,inputindex+1,n,output,outputindex+1);	
		
	}
	return;
}

int main()
{
	string table[] = { " ", ".+@$", "abc", "def", 
	"ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
	
	string s;
	cin>>s;
	char output[s.length()];
	nokiakeypad(table,s,0,s.length(),output, 0);
	
	
	//cout<<output[j];
	
}
