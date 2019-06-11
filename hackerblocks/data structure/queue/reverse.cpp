#include<iostream>
#include<queue>

using namespace std;

void reverse(queue<int> &q)
{
	if(q.empty())
	{
		return;
	}
	
	int top = q.front();
	q.pop();
	reverse(q);
	q.push(top);
	return;
}

int main()
{
	queue<int> q;
	int n;
	cin>>n;
	while(n--)
	{
		int num;
		cin>>num;
		q.push(num);
	}
	/*while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}*/
	reverse(q);
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	//q.push(5);q.push(4);q.push(3);
	//cout<<q.front()<<endl;
	//q.pop();
	//cout<<q.front()<<endl;
	return 0;
}





