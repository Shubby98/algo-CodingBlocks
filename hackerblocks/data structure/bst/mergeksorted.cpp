#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    priority_queue < int ,vector<int> , greater<int> > pq;
    int k,n;
    cin>>k>>n;
    for(int i = 0;i<k;i++)
    {

        for(int j = 0;j<n;j++)
        {
            int num;
            cin>>num;
            pq.push(num);
        }
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }

}


