#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

int caldistance(int x ,int y)
{
    return pow(abs(x),2) + pow(abs(y),2);
}


int main()
{
    int k ,q;
    cin>>k>>q;
    priority_queue <long long int> maxheap;
    while(k--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            //cout<<x<<" "<<y<<endl;
            long long int dist = caldistance(x,y);
            if(maxheap.empty())
            {
                maxheap.push(dist);
            }
            if(maxheap.size()<q )
            {
                maxheap.push(dist);
            }
            else
            {
                maxheap.pop();
                maxheap.push(dist);
            }
        }
        if(t==2)
        {
            cout<<maxheap.top()<<endl;
        }
        //cout<<maxheap.top()<<endl;
    }
    return 0;
}
