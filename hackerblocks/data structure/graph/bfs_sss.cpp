#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
/*
template <typename T>
class graph{
    map < T ,list< T > > adjlist;

    public:

    graph(){}

    void addEdge(T u, T v,bool bidir = false){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    void printGraph()
    {
        for(auto i : adjlist){
            cout<<i.first<<"-->";
            for(auto entry : i.second){
                cout<<entry<<" ";
            }
            cout<<endl;
        }
    }

    void bfs_sss(T src)
    {
        map < T , int > dist;
        map < T ,T > parent;
        queue < T > q;
        q.push(src);
        parent[src] = src;

        for(auto node : adjlist)
        {
            dist[node.first] = -1;
        }

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto neighbour : adjlist[node])
            {
                if(dist[neighbour] == -1)
                {
                    q.push(neighbour);
                    parent[neighbour] = node;
                    dist[neighbour] = dist[node] + 6 ;
                }
            }
        }

        for(auto i : dist)
        {
            cout<<i.second<<" ";
        }
    }
};
*/

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

    void bfs_sss(int src)
    {
        int dist[v+1];

        for(int i = 1 ;i<v+1;i++)
        {
            dist[i] = -1;
        }

        int parent[v+1];
        queue<int> q;
        q.push(src);

        dist[src] = 0;
        parent[src] = src;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(auto it = adjlist[curr].begin(); it!=adjlist[curr].end() ; it++)
            {
                int neighbour = *it;
                if(dist[neighbour] == -1)
                {
                    //cout<<"dist value of neighbour"<<dist[neighbour]<<endl;
                    dist[neighbour] = dist[curr] + 6;
                    q.push(neighbour);
                    parent[neighbour] = curr;
                }
            }
        }

        // print distance

        for(int i = 1 ;i<v+1;i++)
        {
            if(i != src)
             cout<<dist[i]<<" ";
        }

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
        int src;
        cin>>src;
        G.bfs_sss(src);
    }

    return 0;
}


