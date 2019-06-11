#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct student 
{
	int roll_no;
	int course;
};

void Insert(queue<student> &q,student s)
{
	stack<student> stack1,stack2;
	if(q.empty())
	{
		q.push(s);
		return;
	}
	while(!q.empty())
	{
		student temp = q.front();
		stack1.push(temp);
		//cout<<temp.course<<"___"<<temp.roll_no<<"q -> s1"<<endl;
		q.pop();
	}
	while(!stack1.empty())
	{
		student temp = stack1.top();
		if(temp.course==s.course)
		{
			stack2.push(s);
		}
		//cout<<temp.course<<"___"<<temp.roll_no<<"s1->s2"<<endl;
		stack2.push(temp);
		stack1.pop();
	}
	while(!stack2.empty())
	{
		student temp = stack2.top();
		//cout<<temp.course<<"___"<<temp.roll_no<<"s2->q"<<endl;
		q.push(temp);
		
		stack2.pop();
	}
	
	return;
}

int main()
{
	queue<student> q;
	int n;
	cin>>n;
	while(n--)
	{
		char op;
		cin>>op;
		if(op=='E')
		{
			student s;
			cin>>s.course>>s.roll_no;
			Insert(q,s);
		}
		if(op == 'D')
		{
			student s = q.front();
			q.pop();
			cout<<s.course<<" "<<s.roll_no<<endl;
			
		}
	}
	
	
	
}
