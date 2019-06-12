#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

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

    void bfs(T src)
    {
        map < T , bool > visited;
        queue < T > q;
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto neighbour : adjlist[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

int main()
{
    graph <int> G;
    G.addEdge(0,1,true);
    G.addEdge(0,4,true);
    G.addEdge(1,2,true);
    G.addEdge(2,4,true);
    G.addEdge(2,3,true);
    G.addEdge(4,3,true);
    G.addEdge(3,5,true);
    G.printGraph();
    G.bfs(0);
    return 0;
}


