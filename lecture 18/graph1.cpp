#include<iostream>
#include<list>
#include<queue>
using namespace std;

class graph
{
	int v;
	list<int>* l;
public:
	graph(int v)
	{
		this->v = v;
		l = new list<int>[v]; 
	}
	
	void addEdge(int src ,int dest,bool bider =false)
	{
		l[src].push_back(dest);	
		if(bider)
		{
			l[dest].push_back(src);
		}
	}
	
	void print()
	{
		for(int i =0; i<v;i++)
		{
			//list<int> :: iterator it;
			cout<<i;
			for(auto it= l[i].begin() ; it !=l[i].end() ; it++ )
			{
				cout<<" --> "<<*it;
			}
			cout<<endl;
		}
	}
	
	void bfs(int vertex)
	{
		
	}
	
	int shortest_path(int vertex)
	{
		int path[v] = {INT_MAX};
		queue<int> q;
		q.push(vertex);
		path[vertex] = 0;
		bool visit[v] = {false};
		visit[vertex] = true;
		while(!q.empty())
		{
			int top = q.front();
			q.pop();
			for(auto it = l[top].begin();it!=l[top].end();it++)
			{
				int curr = *it
				if(visit[curr]==false)
				{
					q.push(curr);
					visit[curr]==true;
					path[curr] = path[top]+1;
				}
				
			}
		}
			
	}	
	
	bool isCycle(int vertex)
	{
		for(int i = 0;i<n;i++)
		{
			if(visited[i]==false)
		}
	}
	
	
	bool IsCycledriver(int vertex,bool visited[],bool Instack)
	{
		if(visited[vertex] == true)
		{
			return false
		}
		for(auto it = l[top].begin();it!=l[top].end();it++)
		{
			int child = *it;
			visited[child] = true;
			bool flag = IsCycledriver(child,visited,Instack)
			if(flag==true)
			{
				return true;
			}
			else
			{
				visited[child] = false;
			}
		}			
	}
	
	
};




int main()
{
	graph g(5);
	g.addEdge(0,1,true);g.addEdge(0,4,true);g.addEdge(0,3,true);
	g.addEdge(1,2,true);
	g.addEdge(2,3,true);g.addEdge(2,4,true);
	
	g.print();
	
}




