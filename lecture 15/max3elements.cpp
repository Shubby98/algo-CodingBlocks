#include<iostream>
#include<queue>

using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int> >p;
	
	int n;
	cin>>n;
	p.push(21);
	p.push(12);
	p.push(98);
	while(n != -1)
	{
		if(p.top()<n)
		{
			p.pop();
			p.push(n);
		}
		cin>>n;
	}
	while(!p.empty())
	{
		cout<<p.top()<<" ";
		p.pop();
	}
	
	
}
