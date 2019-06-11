#include<iostream>

using namespace std;

void _Search(string output,string search[100],int n)
{
	for(int i = 0;i<n;i++)
	{
		int k = 0;
		int j=0;
		while(search[i][k]!='\0')
		{
			
			if(search[i][k]==output[j])
			{
				int m=k;
				int n=j;
				while(search[i][m] == output[n])
				{
					m++;
					n++;		
				}
				if(output[n]=='\0')
				{
					cout<<search[i]<<endl;
					return;		
				}		
			}
			k++;
			
		}
	}
}

void nokiakeypad(string table[],string s,int inputindex,int n,
char output[],int outputindex,string search[100])
{
	if(outputindex==n)
	{	
		output[n] = '\0';
		/*
		for(int j=0;j<n;j++)
		{
			cout<<output[j];
		}
		cout<<endl;
		*/
		_Search(output,search,11);
		
		return;
	}
	
	int keypadnum = s[inputindex]-48;
	
	for(int i=0;i<table[keypadnum].length();i++)
	{
		output[outputindex]=table[keypadnum][i];
		nokiakeypad(table,s,inputindex+1,n,output,outputindex+1,search);	
		
	}
	return;
}

int main()
{
	string table[10] = { " ", ".+@$", "abc", "def", 
	"ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
	
	string searchIn[] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
	
	string s;
	cin>>s;
	char output[s.length()];
	nokiakeypad(table,s,0,s.length(),output, 0,searchIn);
	//cout<<searchIn[5][5]<<endl;
//	_Search(s,searchIn,11);
	
	//cout<<output[j];
	
}
