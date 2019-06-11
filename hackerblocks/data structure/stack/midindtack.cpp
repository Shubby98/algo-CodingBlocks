#include<iostream>
#include<stack>

using namespace std;

int mid(stack<int> s)
{
	int mid = (s.size())/2;
	while(mid--)
	{
		s.pop();
	}
	return s.top();
}

int main()
{
	int n;
	stack<int> s;
	cin>>n;
	while(n--)
	{
		int num;
		cin>>num;
		s.push(num);
	}
	cout<<mid(s);
}
