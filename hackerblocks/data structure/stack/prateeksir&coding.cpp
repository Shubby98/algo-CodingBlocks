#include<iostream>
#include<stack>
#include<ctime>
using namespace std;

int main()
{
	
	stack<int> s;
	int q;
	cin>>q;
	int start = clock();
	while(q--)
	{
		int num;
		cin>>num;
		if(num==2)
		{
			int cost;
			cin>>cost;
			s.push(cost);
		}
		else
		{
			cout<<s.top()<<endl;
			s.pop();
		}
	}
	int end = clock();
	cout<<end - start<<endl;
}
