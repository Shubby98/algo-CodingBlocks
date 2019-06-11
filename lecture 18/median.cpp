#include<iostream>
#include
using namespace std;

int med(int num,int median)
{
	if(min)
}


int main()
{
	
	priority_queue< int,vector<int>,greater<int> > min;
	priority_queue <int> max;


	int n;
	cin>>n;
	int median = INT_MAX;
	while(n!=-1)
	{
		if(max.size() > min.size())
		{
			if(n<median)
			{
				min.push(max.top())
				max.pop();
				max.push(n)	
			}
			else
			{
				min.push(nw)
			}
			median = (max.top() + min.top())/2;
		 } 
		 else if( max.size()<min.size())
		 {
		 	if(n<median)
		 	{
		 		min.push(n);
			}
			else
			{
				max.push(min.top());
				min.pop();
				min.push(n);
			}
			median = (max.top() + min.top())/2;
		 }
		
	}
}




