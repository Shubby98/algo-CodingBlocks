#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class heap
{
	vector<int>v;
	
	void heapify(int i)
	{
		int minIndex = i;
		int left = 2*i;
		int right = left + 1;
		if(left < v.size() && v[minIndex] > v[left])
		{
			minIndex = left;
		}
		if(right < v.size() && v[minIndex] > v[right])
		{
			minIndex = right;
		}
		if(minIndex!=i)
		{
			swap(v[i],v[minIndex]);
			heapify(minIndex);
		}
		return ;
		
	}
	
	public:
		heap()
		{
			v.push_back(-1);
		}
		int size()
		{
			return v.size() -1 ;
		}
		bool isEmpty()
		{
			return v.size()==1;
		}
		void insert(int data)
		{
			v.push_back(data);
			int index = v.size()-1;
			while(v[index/2]>v[index])
			{
				swap(v[index/2],v[index]);
				index = index/2;
			}
			return ;
		}
		
		int min()
		{
			if(isEmpty())
			return v[1];
		}
		
		int removemin()
		{
			int top = v[1];
			v[1] = v[size() - 1];
			v.pop_back();
		}
		void print()
		{
			for(int i = 1;i<size();i++)
			{
				cout<<v[i]<<" ";
			}
			return ;
		}
};

int main()
{
	heap p;
	p.insert(4);p.insert(1);p.insert(5);
	p.insert(7);p.insert(2);p.insert(3);
	p.print();
	

}



