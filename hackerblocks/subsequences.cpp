#include<iostream>
#include<string>

using namespace std;

char s[1000][100];
int g = 0;

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


void subseq(char in[],int inputindex,char output[],int outputindex)
{
	if(in[inputindex] == '\0' )
	{
		output[outputindex] = '\0';
		for(int i = 0;i<outputindex;i++)
		{
			s[g][i] = output[i];
		}
		s[g][outputindex] = '\0';
		g++;
        //cout<<output<<endl;
		return;
	}
	subseq(in,inputindex+1,output,outputindex);
	output[outputindex] = in[inputindex];
	subseq(in,inputindex+1,output,outputindex+1);


	return;
}

int main()
{
	int t;
	cin>>t;
	//string s[1000];
	while(t--)
	{
		char in[100];
		char output[100];
		cin>>in;
		subseq(in,0,output,0);
		lexosort(s,g);

		for(int i = 0;i<g;i++)
		{
			cout<<s[i]<<endl;
		}
		//cout<<output;
	}

}
