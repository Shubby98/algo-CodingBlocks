#include<iostream>
#include<unordered_map>
#include<list>
#include<limits.h>
#include<set>
#include<vector>

using namespace std;

class Graph
{
    int v,e;
    unordered_map< int , list< pair< int , int > > > m;
    public:
    Graph(int v,int e){
        this->v = v;
        this->e = e;
    }


    void addEdge(int u,int v,int dist,bool bidir = true)
    {
        m[u].push_back(make_pair(v,dist));
        if(bidir)
            m[v].push_back(make_pair(u,dist));
    }

    void dijkstra(int src)
    {
        vector < int > dist;

        for(int i=0;i<v+1;i++){
            dist.push_back(INT_MAX);
        }

        set < pair <int ,int > > S;
        dist[src] = 0;

        S.insert(make_pair(0,src));

        while(!S.empty()){
            auto p = S.begin();
            int node = p->second;
            int nodeDist = p->first;

            S.erase(p);

            for(auto childpair : m[node])
            {
                int dest = childpair.first;
                if(nodeDist + childpair.second < dist[dest])
                {
                    auto f = S.find(make_pair(dist[dest],dest));
                    if(f!=S.end())
                    {
                        S.erase(f);
                    }

                    dist[dest] = nodeDist + childpair.second;
                    S.insert(make_pair(dist[dest],dest));
                }

            }


        }
        for(int i = 1 ;i<dist.size(); i++ )
        {

            if(dist[i]==INT_MAX)
            {
                cout<<"-1 ";
            }
            else if(src!=i)
            {
                cout<<dist[i]<<" ";
            }
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
        Graph G(v,e);
        while(e--)
        {
            //cout<<"value of m "<<m<<endl;
            int u,v,weight;
            cin>>u;
            cin>>v;
            cin>>weight;
            G.addEdge(u,v,weight);
        }
        int src;
        cin>>src;
        G.dijkstra(src);
    }

}
