#include<iostream>
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
        adjlist = new list<int>[v];
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
        for(int i = 0;i<v;i++)
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

    void bfs(int src)
    {
        queue<int> q;
        q.push(src);
        bool flag[v] = {false};
        flag[src] = true;
        while(!q.empty())
        {
            int curr = q.front();
            cout<<curr<<" ";
            q.pop();
            for(int neighbour: adjlist[curr])
            {

                if(!flag[neighbour])
                {
                    q.push(neighbour);
                    flag[neighbour] = true;
                }
            }

        }

    }

};

int main()
{
    graph g(5,7) ;
    g.addedge(0,1);g.addedge(0,4);
    g.addedge(2,1);g.addedge(4,3);
    g.addedge(2,3);g.addedge(3,1);
    g.printgraph();

    cout<<endl;
    g.bfs(0);

}
