#include<iostream>
#include<stack>

using namespace std;

int dequeue(stack<int> &s)
{
	if(s.size()==1)
	{
		int top = s.top();
		s.pop();
		return top;
	}
	
	int top = s.top();
	s.pop();
	int front = dequeue(s);
	s.push(top);
	return front;
}

int main()
{
	int n;
	cin>>n;
	stack<int> s1,s2;
	for(int i =0;i<n;i++)
	{
		s1.push(i);
	}
	for(int i = 0;i<n;i++)
	{
		cout<<dequeue(s1)<<" ";
	}
	return 0;
}
