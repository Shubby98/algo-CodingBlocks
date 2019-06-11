#include<iostream>
#include<time.h>
using namespace std;

int assignment(int n,char cur,char pre,int i)
{
	if(i == n)
	{
		//cout<<cur<<endl;
		if(cur == 'B' && pre == 'B')
		{
			return 0;
			
		}
		return 1;
	}
	//int sum = 0;
	//cout<<cur;
	int sum	= assignment(n,'A',cur,i+1);
	
	if(cur == 'B' )
	{
		return sum;
	}
	else if(cur == 'A')
	{
		//cout<<cur;
		sum += assignment(n,'B',cur,i+1);
	}
	
	return sum ;

}


int main()
{
	int t;
	cin>>t;
	clock_t start = clock();
	for(;t>0;t--)
	{
		int n = t;
		//cin>>n;
		int ab = 0;
		ab += assignment(n,'A','N',1);
		//cout<<ab<<endl;
		ab += assignment(n,'B','N',1);
		//cout<<ab<<endl;
		cout<<"#"<<n<<" : "<<ab<<endl;
	}
	//cout<<"****";	
	clock_t end = clock();
	cout<<(double)(end-start)<<endl;
	//cout<<assignment(3,'B','N',1);
}
