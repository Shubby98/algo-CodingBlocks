#include<iostream>
#include<unordered_set>
using namespace std;


int main()
{
	int n;
	unordered_set <int> hash;
	cout<<"enter no of elements"<<endl;
	cin>>n;	
	for(int i = 0;i<n;i++)
	{
		int num;
		cin>>num;
		if(hash.find(-num)!=hash.end())
		{
			cout<<"pair < "<<num<<" , "<<-num<<" > "<<endl;
		}
		else
		{
			hash.insert(num);
		}
	}
	
	
}
