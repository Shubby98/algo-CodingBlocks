#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int> q[5],seq;
	int n;
	cin>>n;
	while(n--)
	{
		char op;
		cin>>op;
		if(op=='E')
		{
			int course,roll_no;
			cin>>course>>roll_no;
			q[course].push(roll_no);
			seq.push(course);
		}
		if(op == 'D')
		{
			int c = seq.front();
			cout<<c<<" "<<q[c].front()<<endl;
			q[c].pop();
			if(q[c].empty())
			{
				seq.pop();
			}
		}
	}
}
