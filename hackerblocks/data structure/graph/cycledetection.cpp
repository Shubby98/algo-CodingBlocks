#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class graph
{
    int v,e;
    list<int> *adjlist;
public:
    graph(int v,int e)
    {
        this->v = v;
        this->e = e;
        adjlist = new list<int>[v+1];
    }

    void addedge(int u,int v,bool bidir=true)
    {
        adjlist[u].push_front(v);
        if(bidir)
        {
            adjlist[v].push_front(u);
        }
    }

    void printgraph()
    {
        for(int i = 1;i<v+1;i++)
        {
            cout<<i;
            list<int>:: iterator it;
            for(it = adjlist[i].begin(); it!=adjlist[i].end() ; it++ )
            {
                cout<<"-->"<<*it;
            }
            cout<<endl;
        }
    }

    bool IsCycleBFS(int src)
    {
        bool visited[v+1] = {false};
        int parent[v+1] ;

        queue<int> q;
        q.push(src);

        visited[src] = true;
        parent[src] = src;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(auto it = adjlist[curr].begin(); it!=adjlist[curr].end() ; it++)
            {
                int neighbour = *it;
                if(visited[neighbour] && neighbour!=parent[curr])
                {
                    return true;
                }
                else if(!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                    parent[neighbour] = curr;
                }
            }
        }
        return false;

    }

};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
        graph G(v,e);
        while(e--)
        {
            //cout<<"value of m "<<m<<endl;
            int u,v;
            cin>>u;
            cin>>v;
            G.addedge(u,v);
        }
        //cout<<"print graph"<<endl;
        //G.printgraph();
        if(G.IsCycleBFS(1))
        {
            cout<<"yes"<<endl;
        }
        else
            cout<<"no"<<endl;
    }

    return 0;
}


